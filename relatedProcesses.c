/* Программа, осуществляющая однонаправленную связь через pipe между процессом-родителем и процессом-ребенком */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <wait.h>

int main()
{
    int fd[2];
    pid_t pid;

    if (pipe(fd) == -1)
    {
        fprintf(stderr, "Can\'t create pipe\n. Code error: %d", errno);
        exit(-1);
    }

    pid = fork();

    if (pid == -1)
    {
        fprintf(stderr, "Error fork(): %d", errno);
        exit(-1);
    }
    else if (pid == 0)
    {
        char fd_str[10];
        sprintf(fd_str, "%d", fd[1]);
        int exit_code;
        exit_code = execl("./P2", "./P2", fd_str, (char *)NULL);
        if (exit_code == -1)
        {
            fprintf(stderr, "Error execl(): %d", errno);
            exit(-1);
        }
    }
    else
    {
        pid = fork();
        if (pid == -1)
        {
            fprintf(stderr, "Error fork(): %d", errno);
            exit(-1);
        }
        else if (pid == 0)
        {
            char fd_str[10];
            sprintf(fd_str, "%d", fd[0]);
            int exit_code;
            exit_code = execl("./P1", "./P1", fd_str, (char *)NULL);
            if (exit_code == -1)
            {
                fprintf(stderr, "Error execl(): %d", errno);
                exit(-1);
            }
            exit(exit_code);
        }
        else
        {
            wait(&pid);
            close(fd[0]);
            exit(0);
        }
    }
    return 0;
}