#include "lr3-task-1.h"

#include <math.h>
#include <stdio.h>

#include "common.h"

void main() {
    double x1, x2, a, b, step;

    // Ask for x1 and x2 values
    bool x_fetch_result = ask_x_values(&x1, &x2);
    if (!x_fetch_result) return;

    // Ask for step value
    bool step_fetch_result = ask_step(&step);
    if (!step_fetch_result) return;

    // Ask for a and b value
    printf("a and b: ");
    scanf("%lf, %lf", &a, &b);

    print_table_header();

    int counter = 0;
    while (counter > 0 || x1 <= x2) {
        counter++;

        // check when x1 > x2 to print empty fields in the table
        if (counter > 0 && x1 > x2) {
            if (counter > TABLE_FIELD_COUNT) break;
            print_empty_fields();
            continue;
        }
        if (counter == 1) printf("|");

        print_field_with_value(x1);

        // validate function to known is it undefined or not
        bool is_function_defined = validate_function(a, b, x1);
        if (!is_function_defined) {
            print_undefined_field();
        } else {
            // calculate result and print it to next field
            double result = calculate(a, b, x1);
            print_field_with_value(result);
        }

        // reset counter if reached TABLE_FIELD_COUNT value
        if (counter == TABLE_FIELD_COUNT) {
            printf("\n");
            counter = 0;
        }
        // increase x1 by step
        x1 += step;
    }

    print_table_footer();
}

double calculate(double a, double b, double x) {
    return (sqrt(x * x - a) / sin(b * x)) + 4 * cos(fabs(b));
}

bool validate_function(double x, double a, double b) {
    double sin_arg = b * x;
    return sin_arg == PI || sin_arg == (PI / 2) || sin_arg == PI * 2 ||
           (x * x) < a;
}