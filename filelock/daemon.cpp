#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
	int lockd;
	if ((lockd=open("lock",O_CREAT|O_WRONLY|O_EXCL))==-1) {
		perror("can not create 'lock' file");
		exit(1);
	} else {
		if (unlink("lock")==-1) {
			perror("can not unlink 'lock'");
			exit(1);
		}
	}
	sleep(10);
	return 0;
}
