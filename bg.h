#ifndef BG_H_INCLUDED
#define BG_H_INCLUDED
typedef struct {
    pid_t pid;
    char *cmd;
    bool isStop ;
} proc;
#endif
extern proc *proc_list[];
extern int procnum;

bg(char *str, int size){
	pid_t fpid;
	
	//creates the appropriate variables for execvp
	char *argv[size];//for execvp
	int i = 1;
	argv[0] = str;
	while(str= strtok(NULL, " ")){
		argv[i] = str;
		i++;
	}
	argv[i] = NULL;

	
	fpid = fork();

	if (fpid < 0) // fork error
		printf("error in fork!\n");
	else if (fpid == 0) //in child process
	{
		execvp(argv[0],argv);
	}
	else // in parent process
	{
		//new proc to list
		proc nwproc;
		nwproc.pid = fpid;
		nwproc.cmd = str;//todo: see if works
		nwproc.isStop = false;
		proc_list[procnum] = &nwproc;
		wait(NULL);
	}
}

