#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <windows.h>

#include "Scheduler.h"



static void *Proceso1(void)
{
	printf(" %i \n",1);
}

int main()
{
	pthread_t hilo;

	pthread_create(&hilo, NULL, &Proceso1, NULL);
	pthread_join(hilo, NULL);

}