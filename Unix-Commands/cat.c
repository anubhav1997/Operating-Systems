#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char const *argv[]){
	FILE *fptr;
	char curr_dir[100];
	getcwd(curr_dir, sizeof(curr_dir));
	DIR *my_dir = opendir(curr_dir);
	char filename[100];
	strcpy(filename, curr_dir);
	strcat(filename, "/");
	if(argc==2){
		strcat(filename, argv[1]);
 		
	}
	else{
		strcat(filename, argv[2]);
 			
	}
	char line;
 	fptr = fopen(filename, "r");
    if (fptr == NULL){
        printf("Cannot open file \n");
    }
    else if(argc ==2 ){
    	line = fgetc(fptr);
	    while (line != EOF)
	    {
	        printf ("%c", line);
	        line = fgetc(fptr);
	    }
	 
    }
    else if(argc==3){
    	if(!strcmp(argv[1], "-T")){
    		line = fgetc(fptr);
		    while (line != EOF)
		    {
		        if(&line == "\t"){
		        	printf ("^I");	
		        }
		        else{
		        	printf ("%c", line);
		        	
		        }
		        line = fgetc(fptr);
		    } 
    	}
    	else if(!strcmp(argv[1], "-u")){
    		line = fgetc(fptr);
		    while (line != EOF)
		    {
		    	printf ("%c", line);
		        	
		        
		        line = fgetc(fptr);
		    } 
    	}
    }
 	printf("\n");
    fclose(fptr);
    return 0;

}