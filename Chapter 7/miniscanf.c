#include <stdio.h>
#include <stdarg.h>

void miniscanf(char *, ...);

int main()
{
    //test
    int day,year,month;
    miniscanf("%d/%d/%d",&day,&month,&year);
    printf("%d/%d/%d\n",day,month,year);
    return 0;
}

void miniscanf(char * fmt, ...)
{

    char *p,*sval;
    int *dval;
    float *fval;
    va_list ap;

    va_start(ap,fmt);
    for(p = fmt; *p;p++){
        if(*p!='%'){
            int c = getchar();
            if(c!=*p){
                ungetc(c,stdin);
                return;
            }
            continue;
        }
        p++;
        switch(*p){
            case 'd': 
                dval = va_arg(ap,int*);
                scanf("%d",dval);
                break;
            case 'f':
                fval = va_arg(ap,float*);
                scanf("%f",fval);
                break;
            case 's':
                sval = va_arg(ap,char*);
                scanf("%s",sval);
                break;
            default:
                printf("Incorect format modifier!");
                return;
        }

    }
    va_end(ap);
}