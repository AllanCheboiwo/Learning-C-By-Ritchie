#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

int miniprintf(char *,  ...);

int main(){

    int cnt = miniprintf("My name is %s and I am %d years old\n","Allan",100);
    printf("%d\n",cnt);
    return 0;
}

int miniprintf(char *fmt, ...)
{
    va_list ap;
    char *p, *sval;
    int ival,cval,charcnt,finalVal;
    charcnt = 0;
    int leftALigned = 0;
    double dval;
    int precision=0;

    va_start(ap,fmt);

    for(p=fmt;*p;p++){
        if(*p!='%'){
            putchar(*p);
            charcnt+=1;
            continue;
        }
        p++;

        if(*p=='-'){
            leftALigned = 1;
            p++;
        }
        if(isdigit(*p)){
            finalVal=0;
            while(isdigit(*p))
                finalVal = 10*finalVal+(*p++-'0');
        }
        if((*p=='.')){
            p++;
            precision=0;
            while(isdigit(*p))
                precision = 10*precision+(*p++-'0');
        }
        switch(*p){
            case 'd':
                ival = va_arg(ap,int);
                charcnt+=printf("%d",ival);
                break;
            case 'f':
                dval = va_arg(ap,double);
                charcnt+=printf("%f",dval);
                break;
            case 'c':
                cval = va_arg(ap,int);
                putchar(cval);
                charcnt+=1;
                break;

            case 's':
                for(sval = va_arg(ap,char *);*sval;sval++){
                    putchar(*sval);
                    charcnt+=1;
                }
                    
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap);
    return charcnt;
}

/*
Deal with -56.2s

leftALigned=0;



*/