#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 100

int main(int argc,char*argv[])
{

    char lfile1[MAXLINE];
    char lfile2[MAXLINE];
    if(argc<2||argc>3){
        fprintf(stderr,"Incorrect command format. Should be command file1 file2!\n");
        return 1;
    }

    FILE *file1 = fopen(argv[1],"r");

    if(!file1)
        fprintf(stderr,"Error opening the file 1!\n");

    FILE *file2 = fopen(argv[2],"r");

    if(!file2)
        fprintf(stderr,"Error opening the file 2!\n");  

    while(fgets(lfile1,MAXLINE,file1)&& fgets(lfile2,MAXLINE,file2)){
        if(strcmp(lfile1,lfile2)!=0){
            printf("%s",lfile1);
            fclose(file1);
            fclose(file2);
            return 0;
        }
    }
    if(fgets(lfile1,MAXLINE,file1))
        printf("%s",lfile1);
    if(fgets(lfile2,MAXLINE,file2))
        printf("%s",lfile2);
    

    fclose(file1);
    fclose(file2);
    return 0;
    

}