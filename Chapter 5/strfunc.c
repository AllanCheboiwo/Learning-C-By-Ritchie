#include <stdio.h>

size_t strlength(char *s);
void strcopy(char *s,char *t);
int strcompare(char *s,char *t);
void strconcat(char *s,char *t);
int strend(char *s, char t);

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

    char firstName[] = "Allan";
    char secondName[] = "Cheboiwo";
    strconcat(firstName,secondName);
    printf("The concatenated string is: %s \n",firstName);
    char t = 'o';
    printf("Is char %c at the end of string %s? 1 is yes 0, is no. Answer: %d \n",t,firstName,strend(firstName,t));

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
    while((*s++=*t++));
}

int strcompare(char *s, char *t)
{
    for(;*s==*t;s++,t++)
        if(*s=='\0')
            return 0;
        return *s-*t;

}
void strconcat(char *s,char *t)
{
    while(*s)
        s++;
     
    while((*s++=*t++));
}

int strend(char *s, char t)
{
    if(!s)
        return 0;
    
    char last_char = '\0';
    while(*s){
        last_char= *s;
        s++;
    }

    return last_char==t? 1:0;
}
