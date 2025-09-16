#include <stdio.h>

#define IN 1
#define OUT 0
#define N 128
#define MAX_LEN 50
#define MIN_WLEN 1

int maxWordLength();
void histogram2();
void histogram();

int main()
{
    // int c, i, nwhite, nother;
    // int ndigits[10] = {0};

    // nwhite = nother = 0;
    // while((c=getchar())!=EOF){
    //     if(c>='0' && c<='9')
    //         ++ndigits[c-'0'];
    //     else if(c == ' ' || c == '\t' || c == '\n')
    //         ++nwhite;
    //     else
    //         ++nother;
    // }

    // printf("digits =");
    // for(i=0;i<10;++i)
    //     printf(" %d",ndigits[i]);
    // printf("\nWhite space = %d\nOther = %d \n",nwhite,nother);

    //histogram2();
    histogram();
}

//Exercise 1-13
void histogram(){

    int c, n, i, j, k, state, wlen;

    wlen = 0;
    state = OUT;

    int hist[MAX_LEN] = {0};
    
    while((c=getchar())!=EOF){
        if(c == '\n' || c == ' ' || c == '\t'){
            if(state == IN){
                if (wlen < MAX_LEN) {
                    ++hist[wlen];
                } else {
                    ++hist[MAX_LEN - 1];
                }
                wlen = 0;
            }
            state = OUT;
        }
        else{
           if(state == OUT)
                state = IN;
            ++wlen;
        }
    
    }

    if (state == IN && wlen > 0) {
        if (wlen < MAX_LEN) {
            ++hist[wlen];
        } else {
            ++hist[MAX_LEN - 1];
        }
    }
    for(i = MIN_WLEN; i < MAX_LEN ; ++i){
        printf("%d: ",i);
        k = hist[i];
        for(j = 0; j < k; ++j)
            printf("-");
        printf("(%d)\n",k);
    }

}

// Exercise 1-14
void histogram2(){

    int c,i,j;
    int hist[N] = {0};

    while((c=getchar())!=EOF){
        if (c < N)
            ++hist[c];
    }

    for(i = 32; i < 127; ++i){ //printable ascii
        printf("%c ",i);
        int k = hist[i];
        for(j = 0; j < k; ++j)
            printf("-");
        printf("(%d)\n",k);
    }
}
