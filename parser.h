#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef enum { 
  NODE_VAR, 
  NODE_AND, 
  NODE_OR, 
  NODE_IMPLIES, 
  NODE_NOT 
} NodeType;

typedef struct Node {
  NodeType type;
  char var; // Only valid if type == NODE_VAR
  struct Node *left;
  struct Node *right;
} Node;

Node *parse_expression(const char **s);
Node *parse_term(const char **s);
Node *parse_factor(const char **s);
Node *parse_base(const char **s);
Node *parse_variable(const char **s);
void free_tree(Node *node);