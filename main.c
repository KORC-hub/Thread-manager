#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <windows.h>

#include "Scheduler.h"



static void *Proceso1(void)
{
	for (int i = 0; i < 30; i)
	{
		if (scheduler[0][1] == 2)
		{
			printf("-- proceso 1: proceso en primer plano \n");
			++i;
			Sleep(800);
		}
	}

	scheduler[0][1] = 4;
	--infoThread[1];
	++infoThread[2];
}

static void *Proceso2(void)
{
	for (int i = 0; i < 10; i)
	{
		if (scheduler[1][1] == 2)
		{
			printf("-- proceso 2: proceso en primer plano \n");
			++i;
			Sleep(800);
		}
	}

	scheduler[1][1] = 4;
	--infoThread[1];
	++infoThread[2];
}

static void *Proceso3(void)
{
	for (int i = 0; i < 15; i)
	{
		if (scheduler[2][1] == 2)
		{
			printf("-- proceso 3: proceso en primer plano \n");
			++i;
			Sleep(800);
		}
	}

	scheduler[2][1] = 4;
	--infoThread[1];
	++infoThread[2];
}


int main()
{
	pthread_t hilo1, hilo2, hilo3, hiloLongScheduler, hiloShortScheduler;

	pthread_create(&hiloLongScheduler, NULL, &longScheduler, NULL);
	pthread_create(&hiloShortScheduler, NULL, &shortScheduler, NULL);
	

	pthread_create(&hilo1, NULL, &Proceso1, NULL);
	pthread_create(&hilo2, NULL, &Proceso2, NULL);
	pthread_create(&hilo3, NULL, &Proceso3, NULL);

	pthread_join(hiloLongScheduler, NULL);
	pthread_join(hiloShortScheduler, NULL);
	pthread_join(hilo2, NULL);
	pthread_join(hilo1, NULL);
	pthread_join(hilo3, NULL);
	
	

}