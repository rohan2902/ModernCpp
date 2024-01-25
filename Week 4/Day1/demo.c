#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>


int main()
{
    int id = fork();

    if(id==0){
        printf("%s","\nThis statement is printed in the child\n");
        printf("Process ID is %d and my parents ID is : %d",getpid(),getppid());
    }
    else{
        printf("%s","\nThis comes from the parent\n");
        printf("Process ID is %d and my parents ID is : %d",getpid(),getppid());
    }
    return 0;
}
