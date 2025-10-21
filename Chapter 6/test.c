#include <stdio.h>

struct point{
    int x;
    int y;
};
int main(){
    struct point origin, *pp;
    pp = &origin;
    printf("origin is (%d,%d)\n",pp->x,pp->y);
    return 0;
}
