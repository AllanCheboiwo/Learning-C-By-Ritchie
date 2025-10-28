#include <stdio.h>
#include <stdlib.h>
void filecopy(FILE *,FILE *);
int main(int argc, char *argv[]){
    FILE *fp;
    int c;
    char *prog = argv[0];
    if(argc==1)
        filecopy(stdin,stdout);
    else{
        while(--argc>0){
            fp = fopen(*++argv,"r");
            if(!fp){
                fprintf(stderr,"%s: Error! Cant open the file: %s\n",prog,*argv);
                exit(1);
            }
            filecopy(fp,stdout);
            fclose(fp);
            putchar('\n');
        }
    }
    if(ferror(stdout)){
        fprintf(stderr,"%s: error while writing to stdout\n",prog);
        exit(2);
    }

    exit(0);
}

void filecopy(FILE *input, FILE* output)
{
    int c;
    
    while((c=getc(input))!=EOF)
        putc(c,output);
}