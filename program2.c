#include <stdio.h>
#include <math.h>

int main(void)
{
    int n, i;
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
    power = 1.0;
    sign = -1.0;
    ops += 4;

    for (i = 1; i <= n; i++)
    {
        power = power * x;
        sign = -sign;
        term = sign * power / i;
        sum = sum + term;
        ops += 12;
    }
    ops += 1;

    exact = log(1.0 + x);
    error = fabs(exact - sum);

    printf("Result (dynamic programming): %.7f\n", sum);
    printf("Error: %.7e\n", error);
    printf("Number of operations: %ld\n", ops);

    return 0;
}