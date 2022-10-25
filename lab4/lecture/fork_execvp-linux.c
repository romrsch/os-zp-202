#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    pid_t child_pid;
    child_pid=fork();

if( child_pid==0)
    execvp("ls -la", argv);
    fprintf(stdout,"The main program is yet running!\n");
return 0;
}

