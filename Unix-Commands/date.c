#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]){
	// struct date d;
	// getdate(&d);
	// printf("date is %d %d %d\n", d.da_day, d.da_mon, d.da_year);

	time_t mytime;
	mytime = time(NULL);
	printf("%s", ctime(&mytime));


	return 0;
}
