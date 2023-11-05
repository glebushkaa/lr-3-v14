#include <math.h>
#include <stdio.h>
#include <windows.h>

double calculate(double x);

void main() {
    double x1, x2, steps;
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
        if (i <= 5) {
            printf("\033[33m     undefined\033[0;39m|");
            if (counter == 3) {
                printf("\n");
                counter = 0;
            }
            continue;
        }
        double result = calculate(i);
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

double calculate(double x) {
    double first_part = (log(x - 5) + 2) / x - 1;
    double second_part = 0;
    for (int n = 2; n >= 4; n++) {
        second_part += (pow(3, n) - x) / (n + 5);
    }
    double third_part = 2 * sqrt(log(fabs(x - 4)));
    return first_part + second_part + third_part;
}
