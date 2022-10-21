//Scheduler = {proceso Id, estado del proceso, prioridad del proceso}
// estados: 0-nuevo, 1-listo, 2-ejcucion, 3-bloqueado, 4-terminado
// prioridad: 0 --> n
int scheduler[3][3] = {1, 0, 0, 2, 0, 1, 3, 0, 1};

// datos = {Nprocesos, Hilos Activos, Hilos terminados}
int infoThread[3] = {3, 0, 0};

static void longScheduler(void)
{

	while (infoThread[2] < 3)
	{
		printf("---------------- El Planificador 1 se ejecuto (hA %i, hT %i \n", infoThread[1], infoThread[2]);

		for (int prioridad = 0; prioridad < 2; ++prioridad)
		{
			for (int id = 0; id < infoThread[0]; ++id)
			{
				if (infoThread[1] < 2 && scheduler[id][1] == 0 && scheduler[id][2] == prioridad)
				{
					scheduler[id][1] = 1;
					++infoThread[1];
				}
			}
		}

		sleep(2);
	}
}