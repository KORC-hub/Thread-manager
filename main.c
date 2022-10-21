#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <windows.h>

#include "Scheduler.h"



static void *Proceso1(void)
{

}

static void *Proceso2(void)
{
	// ksjhfksjdbf
}

static void *Proceso3(void)
{
	// lsdkjfjksdbf
}


int main()
{
	pthread_t hilo1, hiloLongScheduler, hiloShortScheduler;

	pthread_create(&hilo1, NULL, &Proceso1, NULL);
	pthread_join(hilo1, NULL);

}