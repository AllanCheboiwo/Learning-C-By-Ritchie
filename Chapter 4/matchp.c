#include <stdio.h>

#define MAXLINESIZE 1000 /* Maximum line length */
char pattern[] = "ould";
int getLine(char line[], int max);
int strindex(char line[], char target[]);

int main()
{
    char line[MAXLINESIZE];
    int found = 0;
    while(getLine(line,MAXLINESIZE)>0){
        while(strindex(line,pattern)>=0){
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

// int strindex(char line[],char target[])
// {
//     int i,j,k;

//     for(i=0;line[i]!='\n' && line[i]!='\0';i++)
//         for(j=i,k=0;target[k]!='\0' && line[j]==target[k]; j++,k++)
//             ;
//         if(k>0 && target[k]=='\0')
//             return i;
//     return -1;
        
// }

int strindexR(char line[],char target[])
{
    int i,j,k;
    int index=-1;
    for(i=0;line[i]!='\n' && line[i]!='\0';i++){

        for(j=i,k=0;target[k]!='\0' && line[j]==target[k]; j++,k++){
            ;
        }
        if(k>0 && target[k]=='\0'){
            index =i;
        }
    }       
    return index;
}



