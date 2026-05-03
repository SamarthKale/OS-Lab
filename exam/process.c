
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#define BUFLEN 50
int main()
{
    int i;
    char buffer[BUFLEN+1];
    pid_t fork_return;
    fork_return=fork();
    if(fork_return==0)
    {
        strncpy(buffer,"Samruddhi is in CHILD\n",BUFLEN);
        buffer[BUFLEN]='\0';
    }
    else if(fork_return>0)
    {
        strncpy(buffer,"Samruddhi is in PARENT\n",BUFLEN);
        buffer[BUFLEN]='\0';
    }
    else 
    {
        printf("Error in some process\n");
        return 1;
    }
    for(i=0;i<5;i++)
    {
        sleep(2);
        write(1,buffer,strlen(buffer));
    }
}