#include <stdio.h>


size_t strl(char *s);


int main()
{
    char * s = "My name is Allan Cheboiwo";
    printf("The length of the string is %zu",strl(s));
}

size_t strl(char *s)
{
    char * p =s;

    while(*p!='\0')
        p++;
    
    return p-s;

}
