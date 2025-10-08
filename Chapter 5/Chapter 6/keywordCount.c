#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct key {
    char *word;
    int count;
} keytab[] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,      
    "continue", 0,
    "default", 0,
    "do", 0,
    "double", 0,
    "else", 0,
    "enum", 0,
    "extern", 0,
    "float", 0,
    "for", 0,
    "goto", 0,
    "if", 0,
    "int", 0,
    "long", 0,
    "register", 0,
    "return", 0,
    "short", 0,
    "signed", 0,
    "sizeof", 0,
    "static", 0,
    "struct", 0,
    "switch", 0,
    "typedef", 0,
    "union", 0,
    "unsigned", 0,
    "void", 0,
    "volatile", 0,   
    "while", 0
};

#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof(keytab[0]))
#define MAXBSIZE 100

int buffer[MAXBSIZE];
int fp=0;

int getWord(char *,int);
int getch(void);
void ungetch(int);
int binSearch(char *,struct key*,int);

int main(){
    int n,c;
    char word[MAXWORD];

    while((c=getWord(word,MAXWORD))!=EOF){
        if(isalpha(c))
            if((n=binSearch(word,keytab,NKEYS))>=0){
                printf("FOUND KEYWORD: %s\n", word);
                keytab[n].count++;
            }
    }
    for(n=0;n<NKEYS;n++)
        if(keytab[n].count>0)
            printf("%4d %s\n",keytab[n].count,keytab[n].word);
    return 0;
}
int getWord(char *word,int lim){
    int c;
    char *w = word;

    while(isspace(c=getch()))
        ;
    if(c!=EOF)
        *w++ = c;
    if(!isalpha(c)){
        *w='\0';
        return c;
    }
    for(;--lim>0;w++)
        if(!isalnum(*w=getch())){
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}

int binSearch(char *word,struct key tab[],int n){
    int cond;
    int low,high,mid;

    low=0;
    high=n-1;

    while(low<=high){
        mid = (low+high)/2;
        if((cond=strcmp(word,tab[mid].word))<0)
            high = mid-1;
        else if(cond>0)
            low = mid+1;
        else    
            return mid;
    }
    return -1;
}


int getch(void){
    return fp>0? buffer[--fp]: getchar();
}

void ungetch(int c){
    if(fp>=MAXBSIZE){
        printf("Buffer is full!!!\n");
    }else{
        buffer[fp++] = c;
    }
}
