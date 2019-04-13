//============================================================================
// Name        : hello.cpp
// Author      : Daniel Georiev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define START_NUM_THREADS 5

size_t num_threads = START_NUM_THREADS, threads_ctr = 0, resourcesUsed = 0, resources = 0, buildings = 0;

pthread_mutex_t resource_mutex;
pthread_mutex_t tasks_mutex;
pthread_cond_t cond_var;
pthread_t threads[100];
pthread_t reading_thread;
char buffer [100];
size_t taskCtr = 0;

void *GetResources(void *data);
void *Building(void *data);
void *TrainingWarrier(void *data);
void *func(void *data);


void *GetResources(void *data){

	size_t thread_num = (size_t)data;
	struct timespec to;

	while(1){

		pthread_mutex_lock(&resource_mutex);
	
		clock_gettime(CLOCK_REALTIME, &to);
		to.tv_sec += 2;	
		pthread_cond_timedwait(&cond_var, &resource_mutex, &to);

		if (!(resources + resourcesUsed < 4096 && num_threads < 20)){
			pthread_mutex_unlock(&resource_mutex);
			pthread_exit(0);
			
		}

		else if (taskCtr){
			pthread_mutex_lock(&tasks_mutex);
			printf("You got a task! \n");
			taskCtr = 0;
			pthread_mutex_unlock(&tasks_mutex);

			pthread_mutex_unlock(&resource_mutex);
			func((void*)thread_num);
		}

		printf("Worker %zd is searching\n", thread_num);		
		sleep(3);
		printf("Worker %zd is transporting\n", thread_num);
		sleep(3);
		
		/* Doing this check in order to collect the last one resource at the field */
		if (resources + resourcesUsed < 4095) resources += 5;
		else resources += 1;

		printf("Worker %zd unloaded resources to base station.\n", thread_num);
		sleep(1);
		printf("Recources in the base station: %zd\n", resources);
			
		pthread_mutex_unlock(&resource_mutex);

	}  
}

void *Building(void *data){

	size_t thread_num = (size_t)data;

	if (resources >= 100){
		pthread_mutex_lock(&resource_mutex);

		printf("Worker %zd is constructing new building barracks\n", thread_num);

		resources -= 100;
		resourcesUsed += 100;
		pthread_mutex_unlock(&resource_mutex);

		sleep(20);
		buildings ++;
		printf("Worker %zd completed new building\n", thread_num);

	} else {
		printf("Not enough resources.\n");
	}
	
	return 0;
}

void *TrainingWarrier(void *data){

	size_t thread_num = (size_t)data;
	int error = 0;
	size_t errStatus = 0;

	if (resources >= 25 && buildings){
		pthread_mutex_lock(&resource_mutex);

		printf("Warrier is being trained.\n");
		resources-=25;
		resourcesUsed += 25;
		pthread_mutex_unlock(&resource_mutex);

		sleep(2);
		printf("Warrior is ready for duty.\n");
		
		pthread_create(&threads[threads_ctr], NULL, GetResources, (void*)threads_ctr);
		printf("Warrier %zd will start work soon.\n", num_threads);
		num_threads++;
		
		error = pthread_join(threads[threads_ctr++], (void**)&errStatus);

		if (error != 0){
			printf("Error joining tread! %zd Error code: %zd \n", threads_ctr, errStatus);
		}

	} else if (buildings) printf("Not enough resources.\n");
	else if (resources >= 25) printf("You should have building barrack to train warriers.\n");
	else  printf("You should have building barrack and enough resources for this action.\n");

	return 0;
}

void *ReadingFromStdin(){
	while(1){
		scanf(" %c", &buffer[0]);
		printf("I read this: %c\n", buffer[0]);

		pthread_cond_broadcast(&cond_var);

		pthread_mutex_lock(&tasks_mutex);
		taskCtr = 1;
		
		pthread_mutex_unlock(&tasks_mutex);

	}
	return 0;
}

void *func(void* data) {

	size_t thread_num = (size_t)data;
	printf("Task %c will be worked from worker number %zd.\n", buffer[0], thread_num);

	switch (buffer[taskCtr]) {
		case 's':
			printf("i'm here\n");
			GetResources((void*)thread_num);
			break;
		case 'w':
			TrainingWarrier((void*)thread_num);
			break;
		case 'b':
			Building((void*)thread_num);
			break;
		default:
			printf("Unknown command. Worker %zd will continue it's duty of searching resources.\n", thread_num);
			break;
	}
	GetResources((void*)thread_num);
	pthread_exit(0);
}


int main(int argc, char *argv[]){	

	int error = 0;
	size_t errStatus = 0;

	pthread_mutex_init(&resource_mutex, NULL);
	pthread_mutex_init(&tasks_mutex, NULL);
	pthread_cond_init(&cond_var, NULL);

	printf("Game begins!\n");
	printf("Select action: \n s - search for resources; \n w - train a warrier; \n b - biuld a barrack; \n");
	
	error = pthread_create(&reading_thread, NULL, ReadingFromStdin, NULL);
	if (error != 0){
		printf("Error creating tread!\n");
		return 0;
	}
	
	for (threads_ctr = 0; threads_ctr < START_NUM_THREADS; threads_ctr++){

		error = pthread_create(&threads[threads_ctr], NULL, GetResources, (void*)threads_ctr);
		if (error != 0){
			printf("Error creating tread!\n");
			return 0;
		}
	}
	
	for (threads_ctr = 0; threads_ctr < START_NUM_THREADS; threads_ctr++){
		
		error = pthread_join(threads[threads_ctr], (void**)&errStatus);

		if (error != 0){
			printf("Error joining tread! %zd Error code: %zd \n", threads_ctr+1, errStatus);
			return 0;
		}
	}
		
	
	pthread_mutex_destroy(&resource_mutex);
	pthread_mutex_destroy(&tasks_mutex);
	pthread_cond_destroy(&cond_var);

	size_t gatheredResources = resources + resourcesUsed;
	size_t leftResources = 4096 - gatheredResources;

	printf("\nCongratulations! You won!\n ");
	printf("Total resources on the field: 4096\n Gathered resources: %zd\n Resources left: %zd\n", gatheredResources, leftResources);
	pthread_exit(0);

	return 0;
}