#include <stdio.h>

/*
Basic Pattern
    read a character
        while (character is not end of file indicator)
            output the character just read
            read a character
*/

//Function prototypes
void readv1();
void readv2();
int charCountV1();
double charCountV2();

int main(){
    //readv1();
    // readv2();
    // printf("%d\n",getchar()!=EOF);
    // printf("%d\n",EOF);
    printf("The number of characters in input stream is: %.0f\n",charCountV2());
    printf("The number of characters in input stream is: %d\n",charCountV1());
}

//function definition
void readv1()
{
    int c;
    c = getchar();

    while(c!=EOF){
        putchar(c);
        c = getchar();
    }
}

void readv2()
{
    int c;

    while((c=getchar())!=EOF){
        putchar(c);
    }
}

int charCountV1(){
    long nc;

    nc = 0;

    while(getchar()!=EOF)
        ++nc;

    return nc;
}

double charCountV2(){
    
    double nc;

    for(nc = 0; getchar() != EOF; ++nc)
        ;

    return nc;
}
