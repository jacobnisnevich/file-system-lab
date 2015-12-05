#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define OSPFS_NWRITE 1000
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage: %s NWRITES\n", argv[0]);
		exit(1);
	}
	int fd = open("test/tempfile", O_NONBLOCK | O_CREAT);
	if (fd < 0)
	{
		perror(NULL);
		exit(1);
	}
	if (ioctl(fd, OSPFS_NWRITE, atoi(argv[1])) < 0)
	{
		perror(NULL);
		exit(1);
	}
	close(fd);
}