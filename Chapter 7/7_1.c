#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]){
    int c;
    if(strstr(argv[0],"lower")!=NULL){
        while((c=getchar())!=EOF)
            putchar(tolower(c));
    }else if(strstr(argv[0],"upper")!=NULL){
        while((c=getchar())!=EOF)
            putchar(toupper(c));        
    }else{
        printf("Incorrect call: either tolower or toupper\n");
    }
}
