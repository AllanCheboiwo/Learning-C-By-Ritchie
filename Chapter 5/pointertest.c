#include <stdio.h>

void swap(int* , int*);
int main()
{
    int a = 5,b=6;
    swap(&a,&b);
    printf("%d , %d",a,b);

}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
