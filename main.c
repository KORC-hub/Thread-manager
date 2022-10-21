#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

static void *Proceso1(void)
{
	for (int i = 0; i < 10; ++i)
	{
		printf(" instruccion: %i \n", i+1);
	}
}

int main()
{
	pthread_t hilo;

	pthread_create(&hilo, NULL, &Proceso1, NULL);
	pthread_join(hilo, NULL);

}