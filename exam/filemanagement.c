#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
int main()
{
    int fd;
    char write_buffer[]="This program is to demonstrate File Management system\n";
    char read_buffer[100];
    fd=open("1024134.txt",O_CREAT|O_RDWR,0644);

    write(fd,write_buffer,strlen(write_buffer));

    lseek(fd,0,SEEK_SET);

    read(fd,read_buffer,sizeof(read_buffer));

    printf("%s",read_buffer);
    close(fd);
    
    printf("File Closed Successfully\n");
    return 0;
}
