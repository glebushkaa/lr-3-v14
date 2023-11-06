#ifndef _COMMON_H
#define _COMMON_H

#define TABLE_FIELD_COUNT 3

#include <stdbool.h>

void print_table_header();
void print_table_footer();
void print_undefined_field();

void print_empty_fields();

void print_field_with_value(double value);

/**
 * @return bool which represents whether result successful or not
 */
bool ask_x_values(double* x1, double* x2);


/**
 * @return bool which represents whether result successful or not
 */
bool ask_step(double* step);

#endif