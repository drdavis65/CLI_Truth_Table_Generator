#include "evaluate.h"

bool evaluate(Node *node, bool values[MAX_VARS]) {
  switch (node->type) {
  case NODE_VAR:
    return values[node->var - 'a'];
  case NODE_AND:
    return evaluate(node->left, values) && evaluate(node->right, values);
  case NODE_OR:
    return evaluate(node->left, values) || evaluate(node->right, values);
  case NODE_IMPLIES:
    return !evaluate(node->left, values) || evaluate(node->right, values);
  case NODE_NOT:
    return !evaluate(node->left, values);
  default:
    return false;
  }
}

// Helper function to increment the truth values (treated as binary)
bool increment_values(bool values[], int num_vars) {
    for (int i = num_vars - 1; i >= 0; i--) {
        if (values[i]) {
            values[i] = false; // reset this bit and move to the next one
        } else {
            values[i] = true;  // set this bit and we're done
            return true;       // successfully incremented
        }
    }
    return false; // overflow, we've covered all combinations
}


void generate_truth_table(Node *expr, const char *input_vars, int num_vars) {
  bool values[num_vars];
  memset(values, 0, sizeof(values));

  // Print table header
  for (int i = 0; i < num_vars; i++) {
    printf("%c ", input_vars[i]);
  }
  printf("| Result\n");
  for (int i = 0; i < num_vars; i++) {
    printf("--");
  }
  printf("|------\n");

  // Loop through all combinations
  do {
    // Print current combination
    for (int i = 0; i < num_vars; i++) {
      printf("%d ", values[i]);
    }

    // Translate the simple array into the larger array for evaluation
    bool eval_values[MAX_VARS] = {false};
    for (int i = 0; i < num_vars; i++) {
      eval_values[input_vars[i] - 'a'] = values[i];
    }
    // Evaluate and print result
    printf("| %d\n", evaluate(expr, eval_values));

  } while (increment_values(values, num_vars));
}

char *extract_variables(const char *expression) {
  // A boolean array to keep track of the variables we have seen so far
  bool seen[MAX_VARS] = {false};

  // Allocate space for the result. In the worst case, the expression consists
  // of all 26 lowercase letters.
  char *result = (char *)malloc((MAX_VARS + 1) * sizeof(char));
  int idx =
      0; // position in the result string where the next variable will be added

  // Traverse the expression
  while (*expression) {
    if (islower(*expression) && !seen[*expression - 'a']) {
      result[idx++] = *expression;
      seen[*expression - 'a'] = true;
    }
    expression++;
  }
  result[idx] = '\0'; // null-terminate the result string

  return result;
}