#include "common.h"

#include <stdio.h>

void print_table_header() {
    printf(
        "-------------------------------------------------------------------------------------------\n\
|      x       |      f(x)    |      x       |     f(x)     |      x       |      f(x)    |\n\
-------------------------------------------------------------------------------------------\n");
}

void print_table_footer() {
    printf(
        "\n--------------------------------------------------------------------"
        "-----------------------");
}

void print_empty_fields() { printf("              |              |"); }

void print_undefined_field() { printf("\033[33m     undefined\033[0;39m|"); }

void print_field_with_value(double value) {
    if (value > 999999.99 || value < -99999.99) {
        printf(" %#12.2e |", value);
    } else {
        printf(" %#12.2f |", value);
    }
}

bool ask_x_values(double* x1, double* x2) {
    printf("Input range x1, x2: ");
    scanf("%lf, %lf", x1, x2);
    if (*x1 > *x2) {
        printf("Error x1 > x2");
        return false;
    }
    return true;
}

bool ask_step(double* step) {
    printf("step h: ");
    scanf("%lf", step);
    if (*step <= 0) {
        printf("Error step <= 0");
        return false;
    }
    return true;
}