#MAKEFILE FOR relatedProcesses

# Compile relatedProcesses.c normally
relatedProcesses: relatedProcesses.c
	gcc -o relatedProcesses relatedProcesses.c

# Compile P1.c normally
P1: P1.c
	gcc -o P1 P1.c

# Compile P2.c normally
P2: P2.c
	gcc -o P2 P2.c

# Compile relatedProcesses.c && P1.c && P2.c && unrelatedProcess_1.c && unrelatedProcess_2.c
all: relatedProcesses.c P1.c P2.c unrelatedProcess_1.c unrelatedProcess_2.c
	gcc -o relatedProcesses relatedProcesses.c
	gcc -o P1 P1.c 
	gcc -o P2 P2.c 
	gcc -o unrelatedProcess_1 unrelatedProcess_1.c
	gcc -o unrelatedProcess_2 unrelatedProcess_2.c

# Compile unrelatedProcess_1.c normally
unrelatedProcess_1: unrelatedProcess_1.c
	gcc -o unrelatedProcess_1 unrelatedProcess_1.c

# Compile unrelatedProcess_2.c normally
unrelatedProcess_2: unrelatedProcess_2.c
	gcc -o unrelatedProcess_2 unrelatedProcess_2.c

unrelatedProcess: unrelatedProcess_1.c unrelatedProcess_2.c
	gcc -o unrelatedProcess_1 unrelatedProcess_1.c
	gcc -o unrelatedProcess_2 unrelatedProcess_2.c