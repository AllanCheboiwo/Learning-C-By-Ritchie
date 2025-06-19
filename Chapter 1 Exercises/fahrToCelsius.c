#include <stdio.h>

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300*/

int main()
{
    float fahr, celsius;
    float lower,upper,step;

    lower = 0; /* Lower limit of temp scale*/
    upper = 300; /* Upper limit of temp scale*/
    step = 20; /* step size*/

    fahr = lower;
    printf("Temperature conversion table\n");
    printf("Fahr\tCelsius\n");
    while(fahr<=upper)
    {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%3.0f %10.1f\n",fahr,celsius);
        fahr = fahr + step;
    }

}
