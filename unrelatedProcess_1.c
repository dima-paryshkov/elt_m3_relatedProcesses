#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    umask(0);

    int code;

    int fp;
    char* myFifo = "unProc";

    fp = open(myFifo, O_RDONLY);
    if (fp == -1)
    {
        perror("Can\'t open FIFO (open)");
        exit(1);
    }

    int lenghtStr = 30;
    char str[lenghtStr];

    while (!(code = read(fp, str, lenghtStr)));
    if (code == -1)
    {
        perror("Error read from FIFO (read)");
        exit(2);
    }
    else if (code < lenghtStr)
    {
        fprintf(stderr, "Warning: not all string read from FIFO\n");
    }

    fprintf(stdout, "Received string:\n%s\n", str);

    if (close(fp) == -1)
    {
        perror("Can't close FIFO (close)");
        exit(3);
    }

    if (unlink(myFifo) == -1)
    {
        perror("Error delete FIFO (unlink)\n.");
        exit(4);
    }
    exit(0);
}