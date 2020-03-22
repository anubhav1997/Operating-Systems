#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>

int main(void){
	int i = 0;
	while(1){
		// printf("Enter:\n");		
		// scanf("%s",cmd);
		char command[1000];
		char his[1000][1000];
		fgets(command, 1000, stdin);
		command[strlen(command) - 1] = '\0';
		char *cmd = strtok(command, " ");
		
		// printf("hello"ls);
		// printf("cmd: %s\n", cmd);
		if(!strcmp(cmd, "echo")){
			/*printf("in echo\n");
			*/
			char *temp;
			temp = strtok(NULL, " "); 
			// temp[strlen(temp) - 1] = '\0';
			printf("%s\n",temp);
			strcpy(his[i], strcat(strcat(cmd," "),temp) );
			
			// printf("%s\n", strtok(command, " "));
			//printf("%s", his[i]);
			i = i+1;	
		}
		else if(!strcmp(cmd, "exit")) {
			strcpy(his[i],cmd);
			//printf("%s", his[i]);
			i = i+1;
			
			return 0;
		}
		else if(!strcmp(cmd, "cd")){
			
			char *cwd;
		    cwd = strtok(NULL, " ");

		    chdir(cwd);

		    strcpy(his[i],strcat(strcat(cmd," "),cwd));
			//printf("%s", his[i]);
			i = i+1;
			
		    // getcwd(cwd, sizeof(cwd));
		    // printf("Current working dir: %s\n", cwd);
		}
		else if(!strcmp(cmd, "pwd")){
			// printf("In pwd\n");
			strcpy(his[i],cmd);
			//printf("%s", his[i]);
			i = i+1;
			
			char pwd[1024];
			getcwd(pwd, sizeof(pwd));
		    printf("%s\n", pwd);
		}
		else if(!strcmp(cmd, "history")){
			strcpy(his[i],cmd);
			//printf("%s", his[i]);
			i = i+1;
			
			int j = 0;
			while(his[j][0]!='\0'){
				printf("%d %s\n", j+1,his[j]);
				j++;
			}
		}
		else if(!strcmp(cmd, "mkdir")){
			strcpy(his[i],cmd);
			//printf("%s", his[i]);
			i = i+1;
			
			int pid = fork();
		    if (pid == 0) {
		        // printf("%s",my_argv[0]);
		        // mkdir(arg);
				char *arg1 = strtok(NULL, " ");
				char *arg2 = strtok(NULL, " ");
				execl("/home/anubhav/Desktop/Courses/OS/ASS1/mkdir","mkdir",arg1,arg2, (char *)NULL);
			} 
		    else{
		    	wait(NULL);	
		    } 
		}
		else if(!strcmp(cmd, "ls")){
			// printf("in ls\n");
			strcpy(his[i],cmd);
			//printf("%s", his[i]);
			i = i+1;
			
			int pid = fork();
		    if (pid == 0) {
		        // printf("anubhav");
		        // mkdir(arg);
		        char *arg1 = strtok(NULL, " ");
		        if(arg1!=NULL){
		    		execl("/home/anubhav/Desktop/Courses/OS/ASS1/ls", "ls", arg1, (char *)0);
			    	
		        }
		        else{
					execl("/home/anubhav/Desktop/Courses/OS/ASS1/ls", "ls", (char *)0);
		        }
			} 
		    else{
		    	wait(NULL);	
		    } 
		}
		else if(!strcmp(cmd, "rm")){
			strcpy(his[i],cmd);
			//printf("%s", his[i]);
			i = i+1;
			
			int pid = fork();
		    if (pid == 0) {
		        // printf("%s",my_argv[0]);
		        // mkdir(arg);
		        char *arg1 = strtok(NULL, " ");
		        char *arg2 = strtok(NULL, " ");
		        if(arg2!=NULL){
		    		execl("/home/anubhav/Desktop/Courses/OS/ASS1/rm","rm",arg1, arg2,(char*) NULL);
			    	
		        }
		        else{
		        	execl("/home/anubhav/Desktop/Courses/OS/ASS1/rm","rm",arg1,(char*) NULL);
			
		        }
			} 
		    else{
		    	wait(NULL);	
		    } 
		}
		else if(!strcmp(cmd, "cat")){
			strcpy(his[i],cmd);
			//printf("%s", his[i]);
			i = i+1;
			
			int pid = fork();
		    if (pid == 0) {
		        // printf("%s",my_argv[0]);
		        // mkdir(arg);
				char *arg1 = strtok(NULL, " ");
				char *arg2 = strtok(NULL, " ");
		        if(arg2!=NULL){
		        	execl("/home/anubhav/Desktop/Courses/OS/ASS1/cat","cat",arg1, arg2, (char *)NULL);	
		        }
		        else{
		        	execl("/home/anubhav/Desktop/Courses/OS/ASS1/cat","cat",arg1, (char *)NULL);
		        }
				
			} 
		    else{
		    	wait(NULL);	
		    } 

		}
		else if(!strcmp(cmd, "date")){
			strcpy(his[i],cmd);
			//printf("%s", his[i]);
			i = i+1;
			
			int pid = fork();
		    if (pid == 0) {
		        // printf("%s",my_argv[0]);
		        // mkdir(arg);
		    	char *arg1 = strtok(NULL, " ");
				execl("/home/anubhav/Desktop/Courses/OS/ASS1/date", "date", arg1, (char*) NULL);
			} 
		    else{
		    	wait(NULL);	
		    } 

		}
	}
	return 0;
}
