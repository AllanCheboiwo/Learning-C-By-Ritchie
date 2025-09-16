#include <stdio.h>

#define LIMIT 1000 // Limit of the size of input line we will read

/*
    Second edition: the C programming Language by Dennis Ritchie 
    Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input, and
    to delete entirely blank lines.
*/

// Function prototypes
int get_line(char line[], int limit);

int main(){
    char line[LIMIT];
    int n;

    while((n=get_line(line,LIMIT))>0){
        printf("%s",line);
    }
}

int get_line(char s[], int lim)
{
    int c, i, j, trail;

    
    for(i = 0; i< lim-1 && (c=getchar())!=EOF && c!='\n'; ++i )
        s[i]=c;
    
    while(i>0 && ((trail=s[i-1]) == ' ' || trail == '\t'))
        --i;
    
    
    if(c=='\n' && i > 0){

        s[i] = '\n';
        ++i;
        

    }
    s[i] = '\0';

    return i;

}
