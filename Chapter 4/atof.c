#include <stdio.h>
#include <ctype.h>
#include <math.h>
double atof(char s[]);
int main(){
    
    char s[] = " 123.45e-6 ";
    double result = atof(s);
    printf("Your string to number is %f\n",result);

}

double atof(char s[]){
    double val, power,powerX;
    int i,sign,signS,powerVal;
    powerX = 1.0;
    for(i=0;isspace(s[i]);i++);
    sign = (s[i]=='-'? -1:1);
    for(val=0.0;isdigit(s[i]);i++){
        val = val *10.0 + (s[i]-'0');
    }
    if(s[i]=='.')
        i++;

    for(power=1.0;isdigit(s[i]);i++){
        val = val *10.0 + (s[i]-'0');
        power*=10.0;
    }

    if(s[i]=='e' || s[i] == 'E')
    {
        signS = (s[++i] == '-'? -1:1);
        i++;
        for(powerVal=0;isdigit(s[i]);i++){
            powerVal = powerVal *10+ (s[i]-'0');
        }
        if(signS == -1)
            powerX =pow(10.0,-1*powerVal);   
        else
            powerX = pow(10.0,powerVal);   
    }


    return (sign* val/power)*powerX;
}
