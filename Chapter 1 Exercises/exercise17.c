#include <stdio.h>

#define MAX_LINE_SIZE 1000
int getLine(char line[], int limit);

int main()
{
    char line[MAX_LINE_SIZE];
    int i,n;

    
    while((n=getLine(line,MAX_LINE_SIZE))>0){
        if(n>80){
            printf("%d\n",n);
            printf("%s",line);
        }


    }
}

int getLine(char line[],int limit)
{
    int i,c;

    for(i = 0; i<limit-1 && (c=getchar())!=EOF && c!='\n'; ++i){
        line[i] = c;
    }

    if(c == '\n'){
        line[i] = c;
        ++i;
    }
    line[i] = '\0';

    return i;

}


