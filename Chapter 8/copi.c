#include <stdio.h>
#include <unistd.h>

int main(){

    char BUFF[BUFSIZ];
    int n;

    while((n=read(0,BUFF,BUFSIZ))>0)
        write(1,BUFF,n);

    return 0;
}