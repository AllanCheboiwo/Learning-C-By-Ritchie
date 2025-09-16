#include <stdio.h>
#include <ctype.h>
#define swap(t,x,y) {t temp =x; x = y; y = temp;}

int main(){
    int x = 5, y=10;
    swap(int,x,y);
    printf("X i snow %d and y is now %d",x,y);
}
