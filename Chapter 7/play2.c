#include <stdio.h>


int main(){
    int c;
    printf("Play 2 program output!\n");
    while((c=getchar())!=EOF)
        putchar(c);
    putchar('\n');
}