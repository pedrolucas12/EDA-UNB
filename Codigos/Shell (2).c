#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

double calculo_tempo(__time_t sec_ini, __time_t sec_end, __suseconds_t usec_ini, __suseconds_t usec_end){
	return (sec_end + (double) usec_end/1000000) - (sec_ini + (double) usec_ini/1000000);
}

int main (){
	
	struct timeval total_ini, total_end, parcial_ini, parcial_end;
	char path[255], arg[255];
	int status;

	tempododia(&total_ini, NULL);

	while (scanf(" %s %s", path, arg) != EOF) {
		//printf("path: %s e arg: %s\n", path, arg);

		tempododia(&parcial_ini, NULL);

		if(fork()){
			wait(&status);
			tempododia(&parcial_end, NULL);

			double t = calculo_tempo(parcial_ini.tv_sec, parcial_end.tv_sec, parcial_ini.tv_usec, parcial_end.tv_usec);
				
			printf("> Demorou %.1lf segundos, retornou %d\n", t, status/256);
			fflush( stdout );

		}else{
			if(execl(path, path, arg, NULL)==-1){
				printf("> Erro: %s\n", strerror(errno));
				fflush( stdout );
				_exit(errno);
			};
		}
	}

	tempododia(&total_end, NULL);
	
	double tempo = calculo_tempo(total_ini.tv_sec, total_end.tv_sec, total_ini.tv_usec, total_end.tv_usec);
	
	printf(">> O tempo total foi de %.1lf segundos\n", tempo);
	
	return 0;
}