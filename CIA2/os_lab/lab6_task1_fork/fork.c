#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void child_process() {
    printf("Child Process\n");
    printf("PID: %d, Parent PID: %d\n", getpid(), getppid());
}

void parent_process(pid_t child_pid) {
    printf("Parent Process\n");
    printf("PID: %d, Child PID: %d\n", getpid(), child_pid);
}

int main(void) {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        child_process();
    } else {
        parent_process(pid);
    }

    return 0;
}
