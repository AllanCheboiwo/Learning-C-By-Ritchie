#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>
#include <math.h>

#define MAXOP 100 /* max size of operand or operator*/
#define NUMBER '0'/* signal that number was found*/
#define MAXVAL 100 /* maximum depth of val stack*/
#define BUFFSIZE 100



int sp = 0; /* NEXT FREE STACK POSITION*/
double val[MAXVAL]; /*value stack*/
char buf[BUFFSIZE]; /*buffer for ungetch*/
int bufp = 0 ; /*next free position in buf*/



int getop(char[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

/* Reverse Polish Calculator*/
int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while((type=getop(s))!=EOF){
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop()+pop());
            break;
        case '*':
            push(pop()*pop());
            break;
        case '-':
            op2 = pop();
            push(pop()-op2);
            break;
        case '/':
            op2 = pop();
            if(op2!=0.0)
                push(pop()/op2);
            else
                printf("Error: ZERO DIVISION \n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push(fmod(pop(), op2));  // Using fmod for floating-point modulus
            else
                printf("error: zero divisor in modulus\n");
            break;
        case '\n':
            printf("\t%.8g\n",pop());
            break;
        default:
            printf("Error: UNKNOWN COMMAND %s\n",s);
            break;
        }
    }
    return 0;
}


/*push: push f onto value stack */

void push(double f)
{
    if(sp<MAXVAL)
        val[sp++] = f;
    else
        printf("Error: stack full, can't push %g\n",f);
    
}

/* pop : pop and return top val in stack*/
double pop(void)
{
    if(sp>0)
        return val[--sp];
    else{
        printf("Error : stack empty\n");
        return 0.0;
    }
         
}

/* getop: get next char or numeric operand*/

int getop(char s[])
{
    int i,c,sign;

    while((s[0] = c = getch()) == ' ' || c == '\t');

    s[1] = '\0';
    if(c=='-'){
        int next = getch();
        if(isdigit(next) || next =='.'){
            c = next;
            i =1;
            s[1] = c;
            s[2] = '\0';
        }
        else{
            ungetch(next);
            return c;
        }
    }
    else if(!isdigit(c) && c!='.')
        return c; /*not a number*/
    else{
        i=0;
    }

    if(isdigit(c)) /*collect integer part*/
        while(isdigit(s[++i] = c = getch()));
    if(c == '.') /*Collect fraction part*/
        while(isdigit(s[++i] = c = getch()));
    s[i] = '\0';
    if(c!=EOF)
        ungetch(c);
    return NUMBER;
}

int getch(void) /*get a (possibly pushed back) character*/
{
    return (bufp>0) ? buf[--bufp]: getchar();
}

void ungetch(int c) /* psuh character back to input*/
{
    if(bufp>=BUFFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
