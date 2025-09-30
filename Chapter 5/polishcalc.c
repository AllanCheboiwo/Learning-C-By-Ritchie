#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ARGS 100

static float arg_buffer[MAX_ARGS];
static int fp = 0;

float pop(void){
    if(fp<=0){
        printf("Stack is empty!\n");
        return 0.0f;
    }
    
    return arg_buffer[--fp];
}

void push(float digit){
    if(fp>=MAX_ARGS){
        printf("Stack is full!!\n");
    }
    else{
        arg_buffer[fp++]=digit;
    }

}

int is_number(const char *str) {
    char *endptr;
    strtof(str, &endptr);
    return *endptr == '\0';
}

int main(int argc, char *argv[])
{
    while(--argc>0)
    {
        char *c = (*++argv);

        if(is_number(c)){
            push(atof(c));
        }else if(strcmp(c,"-")==0){
            float b = pop();
            float a  = pop();
            push(a-b);
        }else if(strcmp(c,"+")==0){
            float a = pop();
            float b = pop();
            push(a+b);
        }else if(strcmp(c,"*")==0){
            float a = pop();
            float b = pop();
            push(a*b);
        }else if(strcmp(c,"/")==0){
            float b = pop();
            float a = pop();

            if(b==0.0f){
                printf("Division by 0 error!\n");
                return -1;
            }
            push(a/b);
        }else{
            printf("Illegal operation!\n");
            return 1;
        }
    }
    printf("The result is: %f \n",pop());
    return 0;
}
