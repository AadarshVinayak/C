#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

extern char **getln();
void procCmd(char **args);
int specialInstruct(char **args,FILE *fp);


int main() {
	char **args;
	while(1) {
		args = getln();
		int i =0;
		for(i = 0; args[i]!=NULL; i++){
		  printf("Argument %d is %s\n",i,args[i]);
		}
		if(args[0] != NULL)procCmd(args);
	}
	return 0;
}

int specialInstruct(char **args, FILE *fp){
	int i=0;
	for(i=0; args[i]!=NULL; i++){
		if(strcmp(args[i],"&")==0){
			args[i] = NULL;
			return 1;
		}
		if(strcmp(args[i],"<")==0){
		  if((fp=freopen(args[i+1], "r+", stdin))!=NULL){
				args[i+1] = NULL;
				args[i] = NULL;
				return 2;
			} else {
				fp = freopen(args[i+1],"w+",stdin);
				args[i+1]=NULL;
				args[i]=NULL;
				return 2;
			}
		}
		if(strcmp(args[i],">")==0){
		  if((fp=freopen(args[i+1], "r+", stdout))!=NULL){
				args[i+1] = NULL;
				args[i] = NULL;
				return 3;
			} else {
				fp=freopen(args[i+1],"w+",stdin);
				args[i+1]=NULL;
				args[i]=NULL;
				return 3;
			}
		}
	}
	return -1;
}


void procCmd(char **args){
	int back=0;
	int input=0;
	int output=0;
	int number=0;
	FILE *fp = NULL;

	number = specialInstruct(args, fp);

	if(number == 1){
		back = 1;
	} else if(number == 2){
		input = 1;
	} else if(number == 3){
		output=1;
	}

	if(strcmp(args[0],"exit")==0||strcmp(args[0],"EXIT")==0||strcmp(args[0],"Exit")==0){
		exit(1);
	}
	pid_t pid;

	pid = fork();

	int status;

	if(back==1)if(kill (- pid, SIGCONT) < 0)printf("ERROR\n");

	if(pid>0){
		while(wait(&status)!=pid);
	} else if(pid < 0){
		printf("Error: forking child process failes\n");
		if(fp!=NULL)fclose(fp);
		exit(1);
	} else if(pid==0){
		if(execvp(args[0], args)<0){
			printf("ERROR: exec failed\n");
			if(fp!=NULL)fclose(fp);
			exit(1);
		}
	}
	if(input==1||output==1)fclose(fp);
}

