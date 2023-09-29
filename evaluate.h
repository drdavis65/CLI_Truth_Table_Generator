#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "parser.h"

#define MAX_VARS 26

bool evaluate(Node *node, bool values[MAX_VARS]);
bool increment_values(bool values[], int num_vars);
void generate_truth_table(Node *expr, const char *input_vars, int num_vars);
char *extract_variables(const char *expression);
