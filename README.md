### Task 1:

#### The main process creates two child processes and changes their execution context

    Main process: relatedProcess.c
    Child process: P1.c and P2.c

Comloile: 

    make all

Launch: 

    ./relatedProcess

### Task 2:

#### Two unrelated processes are launched, one of them creates a pipe and writes data to it, the other opens it, reads and deletes

Compile: 

    make unrelatedProcess (if you didn't make all)

Launch:

    ./unrelatedProcess_2 in one terminal
    ./unrelatedProcess_1 in other terminal
