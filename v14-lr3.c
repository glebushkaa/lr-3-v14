#include <math.h>
#include <stdio.h>

#define PI 3.14159265358979323846

double calculate(double a, double b, double x);

void main() {
    double x1, x2, a, b, steps;

    printf("Function tabulation\n");
    printf("f(x) = (sqrt(x^2 - a) / sin(bx)) + 4cos(|x|)\n");
    printf("Input\n range x1, x2: ");
    scanf("%lf, %lf", &x1, &x2);
    if (x1 > x2) {
        printf("Error x1 > x2");
        return;
    }
    printf("\nstep h: ");
    scanf("%lf", &steps);
    if (steps <= 0) {
        printf("Error steps <= 0");
        return;
    }
    printf("\na and b: ");
    scanf("%lf, %lf", &a, &b);
    printf(
        "-------------------------------------------------------------------------------------------\n\
|      x       |      f(x)    |      x       |     f(x)     |      x       |      f(x)    |\n\
-------------------------------------------------------------------------------------------\n");
    int counter = 0;
    for (double i = x1; i <= x2 || counter > 0; i += steps) {
        counter++;
        if (counter > 0 && i > x2) {
            if (counter > 3) {
                break;
            }
            printf("              |              |");
            continue;
        }
        if (counter == 1) {
            printf("|");
        }
        if (i > 999999.99 || i < -99999.99) {
            printf(" %#12.2e |", i);
        } else {
            printf(" %#12.2f |", i);
        }
        double sin_arg = b * i;
        if (sin_arg == PI || sin_arg == (PI / 2) || sin_arg == PI * 2 ||
            (i * i) < a) {
            printf(" undefined |");
            if (counter == 3) {
                printf("\n");
                counter = 0;
            }
            continue;
        }
        double result = calculate(a, b, i);
        if (result > 999999.99 || result < -99999.99) {
            printf(" %#12.2e |", result);
        } else {
            printf(" %#12.2f |", result);
        }
        if (counter == 3) {
            printf("\n");
            counter = 0;
        }
    }
    printf(
        "\n--------------------------------------------------------------------"
        "-----------------------");
}

double calculate(double a, double b, double x) {
    return (sqrt(x * x - a) / sin(b * x)) + 4 * cos(fabs(b));
}