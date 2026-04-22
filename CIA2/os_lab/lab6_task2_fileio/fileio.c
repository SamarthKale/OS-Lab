#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void) {
    int sz;
    int fd = open("fout.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd < 0) {
        perror("Error opening file");
        exit(1);
    }

    char message[] = "Hehe from write call\n";

    sz = write(fd, message, strlen(message));

    printf("write(%d, \"%s\", %lu) returned %d\n",
           fd, message, strlen(message), sz);

    close(fd);
    return 0;
}
