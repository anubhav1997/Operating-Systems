#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char const *argv[]){
	struct dirent *files;
	char curr_dir[100];
	getcwd(curr_dir, sizeof(curr_dir));
	DIR *my_dir = opendir(curr_dir);
	if(my_dir==NULL){
		printf("File location doesn't exist");

	}
	else{
		files = readdir(my_dir);
	}
	while(files!=NULL){
		if(argc==1){
		
			printf("%s\t", files->d_name);

		}
		else if(strcmp(argv[1],"-v")==0){
			printf("%s\n", files->d_name);
		}
		else if(strcmp(argv[1],"-Q")==0){
			printf("\"%s\"\n", files->d_name);
			
		}
		files = readdir(my_dir);
		
	}
	// closedir(curr_dir);
	printf("\n");
	return 0;
}