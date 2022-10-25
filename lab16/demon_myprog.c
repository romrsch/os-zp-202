#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	pid_t pid, sid;
	pid = fork();

	if (pid < 0) { exit(EXIT_FAILURE); }
	if (pid > 0) { exit(EXIT_SUCCESS); } //Закрываем родительский процесс

	sid = setsid();
	if (sid < 0) { exit(EXIT_FAILURE); }
	if ((chdir("/")) < 0) { exit(EXIT_FAILURE); }

	printf("It's all right\n");

	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);

{
	FILE* fp;
	int counter=0;
		while(true){
		fp=fopen("/home/user/labs-os-zp202/lab16/test_daemon.txt", "a+");
		fprintf(fp,"%d\n", counter++);
		sleep(10);
		fclose(fp);
}
}
}
