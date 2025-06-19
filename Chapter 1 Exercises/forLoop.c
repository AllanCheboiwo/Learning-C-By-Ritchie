#include <stdio.h>

/*Fahrenheit to Celsius Temperature Converion program*/

int main()
{
    int fahr;
    
    printf("Temperature Conversion Table\nFahr\tCelsius\n");
    for(fahr = 300; fahr >= 0; fahr = fahr - 20)
        printf("%3d %10.1f\n",fahr,(5.0 / 9.0) * (fahr - 32));
}
