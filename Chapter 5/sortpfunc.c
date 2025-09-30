#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <ctype.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];
#define MAXLEN 1000 
#define ALLOCSIZE 1000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void my_qsort(void *lineptr[],int left,int right, int (*comp)(void *,void *),int reverse,int fold);
void swap(void *v[],int,int);
int numcmp(const char *,const char *);
char *strtolower(char *str);

int my_getline(char *, int);
char *alloc(int);
void afree(char *p);

int main(int argc,char *argv[])
{
    int nlines,c;
    int numeric=0,reverse=0,fold=0;
    while(--argc>0 && (*++argv)[0]=='-'){
        while((c=*++argv[0])){
            switch(c){
                case 'r':
                    reverse = 1;
                    break;
                case 'n':
                    numeric=1;
                    break;
                case 'f':
                    fold=1;
                    break;
                default:
                    printf("Sort: Illegal option %c\n",c);
                    return 1;
            }
        }
    }
   if((nlines=readlines(lineptr,MAXLINES))>=0){
        my_qsort((void**) lineptr,0,nlines-1,(int(*)(void*,void*))(numeric?numcmp:strcmp),reverse,fold);
        writelines(lineptr,nlines);
        return 0;
    }else{
        printf("input too big to sort\n");
        return 1;
    }

}

void my_qsort(void *v[],int left, int right,int (*comp)(void *,void *), int reverse,int fold)
{
    int i, last;
    if(left>=right)
        return;
    swap(v,left,(left+right)/2);
    last=left;
    for(i=left+1;i<=right;i++)
    {
        int comparison = (fold) ? (*comp)(strtolower(v[i]),strtolower(v[left])) : (*comp)(v[i],v[left]); 
        if((!reverse && comparison<0) || (reverse && comparison>0))
            swap(v,++last,i);
    }

    swap(v,left,last);
    my_qsort(v,left,last-1,comp,reverse,fold);
    my_qsort(v,last+1,right,comp,reverse,fold);
}


int numcmp(const char *s1, const char *s2)
{
    double v1,v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if(v1<v2)
        return -1;
    else if(v1>v2)
        return 1;
    else 
        return 0;
}


void swap(void *v[], int i,int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else {
        return NULL;
    }
}
void afree(char *p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}


int readlines(char *lineptr[],int maxlines)
{
    int len, nlines;
    char *p,line[MAXLEN];

    nlines = 0;
    while((len=my_getline(line,MAXLEN))>0){
        if( nlines>=maxlines || (p =alloc(len+1))==NULL)
            return -1;
        else{
            strcpy(p,line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}


void writelines(char *lineptr[], int nlines){
    for(int i=0;i<nlines;i++)
        printf("%s\n", lineptr[i]);

}

int my_getline(char *line,int maxlen)
{
    int c,i;
    for(i=0;i<maxlen-1 && (c=getchar())!=EOF && c!='\n';i++)
        *line++ = c;

    // if(c=='\n'){
    //     *line++=c;
    //     i++;
    // }
    *line = '\0';

    return i;
}

char *strtolower(char *str){
    char *p = str;
    while(*p){
        *p = tolower(*p);
        p++;
    }
    return str;
}
