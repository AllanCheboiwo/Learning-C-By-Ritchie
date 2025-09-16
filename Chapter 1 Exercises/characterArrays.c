#include <stdio.h>

#define MAX_LINE_SIZE 1000 /* Maximum input line length */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len; //Current line length
    int max; //max length seen so far
    char line[MAX_LINE_SIZE]; //current input line
    char longest[MAX_LINE_SIZE]; //longest line save

    max = 0;
    while((len = get_line(line, MAX_LINE_SIZE))>0)
        if(len>max){
            max = len;
            copy(longest, line);
        }
    if (max >  0)
        printf("%s",longest);
    return 0;
}

int get_line(char s[], int lim)
{
    int c, i;
    
    for(i = 0; i< lim-1 && (c=getchar())!=EOF && c!='\n'; ++i )
        s[i]=c;
    
    if(c=='\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;

}


void copy(char to[], char from[])
{
    int i;

    i=0;
    while((to[i]=from[i])!='\0')
        ++i;
}
