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
int countLines();
void countBTNL(int count[3]);
void spicy();
void replace();

int main(){
    //readv1();
    // readv2();
    // printf("%d\n",getchar()!=EOF);
    // printf("%d\n",EOF);
    // printf("The number of characters in input stream is: %.0f\n",charCountV2());
    // printf("The number of characters in input stream is: %d\n",charCountV1());
    // printf("The number of Lines in the input stream is: %d\n",countLines());
    // int count[3] = {0};
    // countBTNL(count);

    // printf("Number of blanks: %d\nNumber of tabs: %d\nNumber of New Lines: %d\n",count[0],count[1],count[2]);
    // spicy();
    replace();

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

int countLines()
{
    int c, nl;
    
    nl = 0;

    while((c=getchar())!=EOF){
        if(c=='\n')
            ++nl;
    }

    return nl;
}

void countBTNL(int count[3])
{
    int c;

    while((c=getchar())!=EOF){
        if(c==' ')
            count[0]++;

        if(c=='\t')
            count[1]++;

        if(c=='\n')
            count[2]++;
    }
}
// exercise 1-9
void spicy(){
    int c,count;

    count = 0;
    while((c=getchar())!=EOF){
        if(c==' ' || c=='\t'){
            if(!count)
            {
                putchar(c);
                count = 1;
            }
        }
        else{
            putchar(c);
            count=0;
        }
    }
}

//exercise 1-10
void replace(){
    int c;

    while((c=getchar())!=EOF){
        if(c=='\t')
            printf("\\t");
        else if(c=='\b')
            printf("\\b");
        else if(c=='\\')
            printf("\\\\");
        else
            putchar(c);

    }

}




