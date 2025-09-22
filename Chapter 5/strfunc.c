#include <stdio.h>

size_t strlength(char *s);
void strcopy(char *s,char *t);
int strcompare(char *s,char *t);

int main()
{
    char string[] = "My name is Allan";
    int n = strlength(string);
    char copy[n];
    strcopy(copy,string);
    printf("Original string:    %s\t address: %p\n",string,string);
    printf("Destination string: %s\t address: %p\n",copy,copy);

    if(strcompare(string,copy)==0)
        printf("The strings compared are the same\n");
    else
        printf("The strings compared are not the same\n");


}

size_t strlength(char *s)
{
    char *t =  s;

    while(*s!='\0')
        s++;
    
    return s-t;
}

void strcopy(char *s,char *t)
{
    while((*s++=*t++)!='\0');
}

int strcompare(char *s, char *t)
{
    for(;*s==*t;s++,t++)
        if(*s=='\0')
            return 0;
        return *s-*t;

}

