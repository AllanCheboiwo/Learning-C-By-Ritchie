#include <stdio.h>
#include <string.h>
#define MAXLINESIZE 1000 /* Maximum line length */


int getLine(char line[], int max);


int main(int argc,char *argv[])
{
    char line[MAXLINESIZE];
    int found = 0;
    if(argc!=2)
        printf("Usage: find pattern\n");
    else
        while(getLine(line,MAXLINESIZE)>0){
            if(strstr(line,argv[1])!=NULL){
                printf("%s",line);
                found++;
            }

        }
    return found;
}

int getLine(char line[],int max){
    int c,i;
    i=0;
    while(--max>0 && (c=getchar())!=EOF && c!='\n'){
        line[i++] = c;
    }
    if(c=='\n')
        line[i++]='\n';
    line[i] = '\0';
    return i;
}





