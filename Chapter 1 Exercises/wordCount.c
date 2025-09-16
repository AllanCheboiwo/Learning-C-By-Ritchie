#include <stdio.h>

#define IN  1
#define OUT 0

//Count lines, words, and characters in input
void oneWord();

int main()
{
    // int c, nl, nc, nw, state;

    // state= OUT;
    // nl = nc = nw = 0;
    // while((c=getchar())!=EOF){
    //     ++nc;
    //     if(c=='\n')
    //         ++nl;
    //     if (c == ' ' || c == '\n' || c == '\t')
    //         state = OUT;
    //     else if(state == OUT){
    //         state = IN;
    //         ++nw;
    //     }
    // }
    // printf("%d %d %d\n", nl, nw, nc);
    oneWord();
}

void oneWord()
{
    int c,state;

    state = OUT;

    while((c = getchar()) != EOF){
        if(c == ' ' || c == '\t' || c == '\n'){
            if(state == IN)
                putchar('\n');
            state = OUT;
        }
        else if(state == OUT){
            state = IN;
            putchar(c);
        }
        else
            putchar(c);
    }
}
