#include "parser.h"

Node *create_node(NodeType type, Node *left, Node *right) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->type = type;
  node->left = left;
  node->right = right;
  return node;
}

Node *parse_expression(const char **s) {
  Node *node = parse_term(s);

  while (**s == '+') {
    (*s)++;
    Node *right = parse_term(s);
    node = create_node(NODE_OR, node, right);
  }

  return node;
}

Node *parse_term(const char **s) {
  Node *node = parse_factor(s);

  while (**s == '*') {
    (*s)++;
    Node *right = parse_factor(s);
    node = create_node(NODE_AND, node, right);
  }

  return node;
}

Node *parse_factor(const char **s) {
  if (**s == '~') {
    (*s)++;
    Node *baseNode = parse_base(s);
    return create_node(NODE_NOT, baseNode, NULL);
  } else {
    return parse_base(s);
  }
}

Node *parse_base(const char **s) {
  if (**s == '(') {
    (*s)++;
    Node *expr = parse_expression(s);

    if (**s != ')') {
      fprintf(stderr, "Expected ')'\n");
      exit(1);
    }
    (*s)++;
    return expr;
  } else if (islower(**s)) {
    Node *varNode = parse_variable(s);
    if (**s == '=' && *(*s + 1) == '>') {
      *s += 2;
      Node *expr = parse_expression(s);
      return create_node(NODE_IMPLIES, varNode, expr);
    } else {
      return varNode;
    }
  } else {
    fprintf(stderr, "Unexpected character '%c'\n", **s);
    exit(1);
  }
}

Node *parse_variable(const char **s) {
  if (islower(**s)) {
    char var = **s;
    (*s)++;
    Node *node = create_node(NODE_VAR, NULL, NULL);
    node->var = var;
    return node;
  } else {
    fprintf(stderr, "Expected variable, found '%c'\n", **s);
    exit(1);
  }
}

void free_tree(Node *node) {
  if (node == NULL) {
    return;
  }

  // If the node has a left child, free it.
  if (node->left) {
    free_tree(node->left);
  }

  // If the node has a right child, free it.
  if (node->right) {
    free_tree(node->right);
  }

  // Free the current node.
  free(node);
}
