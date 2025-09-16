#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define BASE 16

int hexToDec(const char[], int);
int letterToInt(char);

int main()
{   
    char *s = "a";
    int n = strlen(s);
    if(n<=0)
    {
        printf("Invalid hex or empty\n");
        return 0;
    }
    int result = hexToDec(s,n);
    if (result == -1){
        printf("Invalid hex char in string");
        return 0;
    }
    printf("%s is : %d in decimal",s,result);
    return 0;
}

int hexToDec(const char oct[], int n){

    int start = 0;
    int total = 0;
    if(n>2 && oct[0] == '0' && tolower(oct[1])=='x')
        start = 2;
    
    for(int i = n-1,sig=0; i>=start; --i){
        int num = letterToInt(oct[i]);
        if(num==-1)
            return -1;
        total+=pow(BASE,sig)*num;
        printf("%f,%d,%d\n",pow(BASE,sig),num,total);
        sig++;
        }

    return total;
}

int letterToInt(char letter) {
    switch(letter) {
        case '0':           return 0;
        case '1':           return 1;
        case '2':           return 2;
        case '3':           return 3;
        case '4':           return 4;
        case '5':           return 5;
        case '6':           return 6;
        case '7':           return 7;
        case '8':           return 8;
        case '9':           return 9;
        case 'A': case 'a': return 10;
        case 'B': case 'b': return 11;
        case 'C': case 'c': return 12;
        case 'D': case 'd': return 13;
        case 'E': case 'e': return 14;
        case 'F': case 'f': return 15;
        default:            return -1;  
    }
}
