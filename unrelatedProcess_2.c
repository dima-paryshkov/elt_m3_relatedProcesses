#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    umask(0);

    int code;
    char *myFifo = "unProc";

    if (mkfifo(myFifo, 0666) == -1)
    {
        if (errno != EEXIST)
        {
            perror("Can\'t create FIFO (mkfifo)");
            exit(10);
        }
    }

    int fp;

    fp = open(myFifo, O_WRONLY);
    if (fp == -1)
    {
        perror("Can\'t open FIFO (open)");
        exit(1);
    }

    char str[] = "Some secret information";
    int lenghtStr = 30;

    code = write(fp, &str, lenghtStr);
    if (code == -1)
    {
        perror("Error write in FIFO (write)");
        exit(2);
    }
    else if (code < lenghtStr)
    {
        fprintf(stderr, "Warning: not all string write in FIFO\n");
    }
    if (close(fp) == -1)
    {
        perror("Can't close FIFO (close)");
        exit(3);
    }
    exit(0);
}