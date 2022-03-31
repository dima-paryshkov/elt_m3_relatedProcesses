#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char** argv)
{
    int fd;

    fd = atoi(argv[1]); 

    int lenghtStr = 30;
    char str[lenghtStr];

    int code;

    while (!(code = read(fd, str, lenghtStr)));
    if (code == -1)
    {
        fprintf(stderr, "Error read P1 process: %d", errno);
        exit(-1);
    }
    else 
        if (code < lenghtStr)
        {
            fprintf(stderr, "Warning: read not all string in P1(read)\n");
        }
    fprintf(stdout, "P1: Received string from P1: \n%s\n", str);
    exit(0);  
}