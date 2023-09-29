#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "evaluate.h"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <expression>\n", argv[0]);
    return 1;
  }

  const char *s = argv[1];

  Node *expr = parse_expression(&s);

  char *variables = extract_variables(argv[1]);

  int num_vars = strlen(variables);

  generate_truth_table(expr, variables, num_vars);

  free(variables);
  free_tree(expr);

  return 0;
}
