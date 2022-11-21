#include<stdio.h>
#include<unistd.h>
#include <sys/wait.h>
#include<stdlib.h>
#include <strings.h>
#include <limits.h>
#include<pthread.h>

int main(int argc , char* argv[]){
	int niceA;
	FILE *fptr;
   	fptr = fopen("niceValueA.txt","r"); 
   	fscanf(fptr,"%d", &niceA);
   	fclose(fptr); 
	struct timespec start, end;
	clock_gettime(CLOCK_REALTIME,&start);
	struct sched_param param;
   	int pid_num = 0;
   	pid_t x = fork();
   	if(x==0){
   		int priority; 
   		// printf("Enter priority for SCHED_OTHER: \n");
   		// scanf("%d" , &priority); 
   		// param.sched_priority = 0;
   		// sched_setscheduler(pid_num, SCHED_OTHER, &param);
   		int n = nice(niceA);
   		printf("nice value for SCHED_OTHER: %d\n",n );
		for(long int i = 0 ; i<4294967296 ; i++){
			continue;
		}
	}
	else{
		wait(NULL); 
		printf("Completed process A\n");
		clock_gettime(CLOCK_REALTIME,&end);
    	double timeA = (end.tv_sec - start.tv_sec)+(end.tv_nsec - start.tv_nsec)*0.000000001;
		printf("time OTHER: %f\n",timeA);
		for(int i = 0 ; i<(int)timeA*10 ; i++){
			printf("|"); 
		}
	}
	return 0;
}