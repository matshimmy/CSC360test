#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "bg.h"
#include "bglist.h"

#define MAXPROC 256
#define USRINPT 256

proc *proc_list[MAXPROC];
int procnum = 0;//current proc number




void main(){
	while(1)
		rinput();

}

rinput(){

	char *usrinput = malloc(USRINPT);
	printf("PMan:> ");
	fgets (usrinput, USRINPT, stdin);

	if(usrinput[0] == '\n'){
		//nothing was pressed
		return;
	}
	int size = strlen(usrinput);
	usrinput[size-1] = '\0';//take off end for execvp
	size--;//decrease size after first command
	char *str; 
	str = strtok(usrinput, " ");



	if(strcmp(str,"bg") == 0){
		str = strtok(NULL, " ");
		bg(str,size);
	}else if(strcmp(str,"bglist") == 0){
		str = strtok(NULL, " ");
		bglist();
	}else if(strcmp(str,"bgkill") == 0 || strcmp(str,"bgstop") == 0 || strcmp(str,"bgstart") == 0){
		str = strtok(NULL, " ");
	}else if(strcmp(str,"pstat") == 0){
		str = strtok(NULL, " ");
	}else{
		printf("command not found\n");
	}
}


