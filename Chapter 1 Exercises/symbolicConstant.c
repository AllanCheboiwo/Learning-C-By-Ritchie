#include <stdio.h>

/*format for defining symbolic constants
#define name replacement list*/
#define LOWER 0 /* Lower limit of the table */
#define UPPER 300 /* Upper limit of the table */
#define STEP 20 /* Step Size */

int main()
{
    int fahr;

    printf("Temperature Conversion table\n");
    printf("Fahr\tCelsius\n");
    for(fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%3d %10.1f\n", fahr, (5.0/9.0) * (fahr-32));
}
