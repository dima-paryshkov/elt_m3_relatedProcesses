#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char** argv)
{
    int fd;

    fd = atoi(argv[1]); 

    char str[] = "Some intresting information";
    int lenghtStr = 30;

    int code;

    code = write(fd, str, lenghtStr);
    if (code == -1)
    {
        fprintf(stderr, "Error write P2 process: %d", errno);
        exit(-1);
    }
    else 
        if (code < lenghtStr)
        {
            fprintf(stderr, "Warning: write not all string in P2(write)\n");
        }
    exit(0);  
}