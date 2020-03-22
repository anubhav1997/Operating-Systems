#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char const *argv[]){
	char curr_dir[100];
	getcwd(curr_dir, sizeof(curr_dir));
	DIR *my_dir = opendir(curr_dir);
	char filename[100];

	if(argc ==1){
		printf("no file/directory given. Refer to --help\n");
	}
	else if(argc ==2){
		// char *filename = argv[2];
		char filename[100];
		strcpy(filename, curr_dir);
		strcat(filename, "/");
		strcat(filename, argv[1]);

		remove(filename);
	}
	else if(strcmp(argv[1],"-f")==0){
		char filename[100];
		strcpy(filename, curr_dir);
		strcat(filename, "/");
		strcat(filename, argv[2]);

		remove(filename);

	}
	else if(strcmp(argv[1],"-v")==0){
		char filename[100];
		strcpy(filename, curr_dir);
		strcat(filename, "/");
		strcat(filename, argv[2]);

		remove(filename);
		printf("%s was removed\n", argv[2]);	
	}


	return 0;

}
