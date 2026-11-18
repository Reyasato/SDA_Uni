
#include <stdio.h>
#include <math.h>

int main(void)
{
    int n, i, j;
    double x = 2.0;
    double sum;
    double power;
    double sign;
    double term;
    double exact, error;
    long ops = 0;

    printf("Enter n: ");
    if (scanf("%d", &n) != 1 || n < 1)
    {
        printf("Invalid input: n must be a natural number\n");
        return 1;
    }

    sum = 0.0;
    ops += 2;

    for (i = 1; i <= n; i++)
    {
        power = 1.0;
        sign = -1.0;
        ops += 4;

        for (j = 1; j <= i; j++)
        {
            power = power * x;
            sign = -sign;
            ops += 7;
        }
        ops += 1;

        term = sign * power / i;
        sum = sum + term;
        ops += 7;
    }
    ops += 1;

    exact = log(1.0 + x);
    error = fabs(exact - sum);

    printf("Result (nested loops): %.7f\n", sum);
    printf("Error: %.7e\n", error);
    printf("Number of operations: %ld\n", ops);

    return 0;
}
