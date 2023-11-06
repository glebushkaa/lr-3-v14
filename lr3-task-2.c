#include "lr3-task-2.h"

#include <math.h>
#include <stdio.h>

#include "common.h"

void main() {
    double x1, x2, step;

    // Ask for x1 and x2 values
    bool x_fetch_result = ask_x_values(&x1, &x2);
    if (!x_fetch_result) return;

    // Ask for step value
    bool step_fetch_result = ask_step(&step);
    if (!step_fetch_result) return;

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

        // check whether x1 less than lowest allowed value or not
        if (x1 <= LOWEST_ALLOWED_X_VALUE) {
            print_undefined_field();
        } else {
            // calculate result and print it to next field
            double result = calculate(x1);
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

double calculate(double x) {
    double first_part = (log(x - 5) + 2) / x - 1;
    double second_part = 0;
    for (int n = 2; n >= 4; n++) {
        second_part += (pow(3, n) - x) / (n + 5);
    }
    double third_part = 2 * sqrt(log(fabs(x - 4)));
    return first_part + second_part + third_part;
}
