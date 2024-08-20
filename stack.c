// Copyright 2023 valeryje

#include "lib.h"

stack *initialization(char token) {
  stack *head = calloc(1, sizeof(stack));
  head->ptr = NULL;
  head->priority = 0;
  prioritizer(head, &token);
  return head;
}

stack *push(stack *operat, char *token) {
  stack *head = calloc(1, sizeof(stack));
  if (!operat) {
    head = initialization(*token);
  } else {
    head->ptr = operat;
    head->value = *token;
    if (*token == '+' || *token == '-') {
      head->priority = 1;
    } else if (*token == '*' || *token == '/' || *token == '%') {
      head->priority = 2;
    } else if (*token == '^') {
      head->priority = 3;
    } else {
      head->priority = 0;
    }
  }
  return head;
}

stack *pop(stack *operat) {
  stack *head = operat->ptr;
  free(operat);
  return head;
}
