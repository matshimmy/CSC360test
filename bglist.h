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

bglist(){
	printf("Process id is: %d The command is: %s\n",500, "This is not done");

}
