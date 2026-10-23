#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/*
    Program requirements
        - print a set of files
        -starting each new one on a new page,
        -with a title and a running page count for each file.

    Plan
        - read the files from the cmd
        - have global count 
        -
*/
#define MAXLINES 25
#define MAXLINE 100

void printHeader(char *,int);
int main(int argc, char *argv[])
{
    char line[MAXLINE];
    int count = 0;
    int nlines;
    FILE *fp;
    while(--argc>0){
        fp = fopen(*++argv,"r");
        nlines=0;
        if(fp==NULL)
        {
            fprintf(stderr,"Error opening file %s\n",*argv);
            continue;
        }
        printHeader(*argv,++count);
        nlines+=3;
        while(fgets(line,MAXLINE,fp)!=NULL){
            if(nlines>=25){
                printHeader(*argv,++count);
                nlines=3;
            }
            printf("%s",line);
            nlines++;
        }
        putchar('\n');
        fclose(fp);
    }
    return 0;
}

void printHeader(char *title, int page_count)
{
    for(int i=0;i<MAXLINE;i++)
        putchar('-');
    putchar('\n');
    printf("Page %d: %s\n\n",page_count,title);
}