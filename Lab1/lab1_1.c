#include <stdio.h>

int main()
{
    double x, y;
    y = 0;
    x = 0;

    printf("Enter x: ");
    scanf("%lf", &x);

    if (x <= -41)
    {
        y = 13 * x * x / 11 - 6;
        printf("y = %.2lf\n", y);
    }
    else
    {
        if (x > 12)
        {
            y = -14 * x - 20;
            printf("y = %.2lf\n", y);
        }
        else
        {
            if (x > -21)
            {
                if (x <= 3)
                {
                    y = -14 * x - 20;
                    printf("y = %.2lf\n", y);
                }
                else
                {
                    printf("Function is not defined for this x.\n");
                }
            }
            else
            {
                printf("Function is not defined for this x.\n");
            }
        }
    }
    return 0;
} 