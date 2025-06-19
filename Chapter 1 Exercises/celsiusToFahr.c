#include <stdio.h>

int main()
{
    /*Variable declaration*/
    float fahr, celsius;
    float upper, lower, step;

    /*Variable assignment*/
    lower = 0.0;
    upper = 300.0;
    step = 20.0;

    celsius = lower;
    printf("Temperature Conversion Table\nCelsius\tFahrenheit\n");
    while(celsius<=upper)
    {
        fahr = (9.0/5.0) * celsius + 32.0;
        printf("%4.0f %10.1f\n",celsius,fahr);
        celsius = celsius + step;
    }

}
