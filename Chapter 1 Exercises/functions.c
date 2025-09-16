#include <stdio.h>

int power(int base, int n);

int main()
{
    printf("2^5 is: %d\n",power(2,5));
}

int power(int base, int n)
{
    int result;

    for(result = 1; n>0 ;--n)
        result*=base;
    
    return result;
}
