#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int Decimal(char *val)
{
	int mul = 1, res = 0;
	for(int i = strlen(val) - 1; i >= 0; i--) {
		res += (val[i] - '0') * mul;
		mul *= 8;
	}
	return res;
}

int main(int argc, char const *argv[])
{
	if(argc == 2) {
		int res = mkdir(argv[1], 0777);
		if(res == -1) {
			printf("Cannot create directory\n");
		} else {
			chmod(argv[1], 0777);
		}
	} else if(argc == 3) {
		if(strcmp(argv[1], "-v") == 0) {
			int res = mkdir(argv[2], 0777);
			if(res == -1) {
				printf("Cannot create directory\n");
			} else {
				chmod(argv[2], 0777);
				printf("Directory created\n");
			}
		} else {
			printf("Couldn't create directory, incorrect argument\n");
		}
	} else {
		if(strcmp(argv[1], "-m") == 0) {
			int res = mkdir(argv[3], 0777);
			if(res == -1) {
				printf("Cannot create directory\n");
			} else {
				int val = Decimal(argv[2]);
				printf("asd: %s\n", argv[2]);
				printf("%d\n", val);
				chmod(argv[3], val);
			}
		}
	}
	return 0;
}