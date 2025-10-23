#include <stdio.h>
#include <ctype.h>
#include <string.h>


#define MAXWORDS 10

int main(int argc, char *argv[]){
    int c;
    int mode=0;
    int len=0;
    if(argc>1){
        if(strcmp(argv[1],"-o")==0)
            mode=0;
        else if(strcmp(argv[1],"-x")==0)
            mode=1;
        else{
            printf("incorect command usage!");
            return -1;
        }
    }
    while((c=getchar())!=EOF){
            if(c=='\n'){
                putchar(c);
                len=0;
                continue;
            }
            if(len>0&&len%MAXWORDS==0){
                putchar('\n');
                len=0;
            }

            if(isprint(c)){
                putchar(c);
                len++;
            }

            else{
                if(mode==0)
                    printf("\\%03o",c);
                else{
                    printf("\\x%02x",c);
                }
                len+=4;
            }
    }

}