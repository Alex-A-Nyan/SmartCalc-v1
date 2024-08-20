// Copyright 2023 valeryje

#include "lib.h"

int processor(char shrt_eq[PARSED_LENGTH], char *err_case) {
  int status = OK;
  int pos = -1;
  double answer[1024] = {0};
  char *token = (char *)calloc(128, sizeof(char));
  token = strtok(shrt_eq, " ");
  stack *operat = NULL;
  int oper_c = 0;  // проверяет состояние возможно унарного оператора
  int break_c = 0;  // cчитает состояние скобок
  int unary_c = 0;  // рассчитывает вероятность появления унарного оператора
  if (!unary(answer, token, &pos, &oper_c)) {
    operat = push(operat, "*");
    token = strtok(NULL, " ");
  } else {
    status = ERROR;
  }
  while (token != NULL) {
    if ((token[0] > 47 && token[0] < 58) || token[0] == '.') {
      numberer(token, answer, &pos, err_case, &unary_c, &oper_c);
    } else if (token[0] == '(' || token[0] > 96) {
      operat = trigobreaketer(operat, token, &break_c, &unary_c, &oper_c);
    } else if (token[0] == ')') {
      operat = backbreaketer(operat, answer, &pos, err_case, &break_c, &oper_c);
    } else {
      operat = lister(operat, token, answer, &pos, err_case, &unary_c, &oper_c);
    }
    if (strlen(err_case) || break_c < 0) break;
    token = strtok(NULL, " ");
  }
  if (!strlen(err_case)) {
    status = closerer(operat, answer, &pos, err_case);
    if (answer[1] != '\0') status = ERROR;
    if (break_c != 0) status = ERROR;
  } else {
    status = ERROR;
  }
  if ((strlen(err_case) && status)) {
    if (err_case == 0) strcat(err_case, "WRONG SEQUENCE");
  } else if ((int)answer[0] == answer[0]) {
    sprintf(err_case, "%d", (int)answer[0]);
  } else {
    sprintf(err_case, "%.7f", answer[0]);
  }
  // cleaner(operat, token);
  return status;
}

int unary(double *answer, char *token, int *pos, int *oper_c) {
  int status = ERROR;
  if (*token == '+' || *token == '-') {
    status = OK;
    (*pos)++;
    if (*token == '+') {
      answer[*pos] = 1;
    } else {
      answer[*pos] = -1;
    }
  }
  (*oper_c)++;
  return status;
}

void numberer(char *token, double *answer, int *pos, char *err_case,
              int *unary_c, int *oper_c) {
  if (strchr(token, '.') != strrchr(token, '.')) {
    strcat(err_case, "IMPOSSIBLE DECIMAL");
  } else if (strcmp(token, ".") == 0) {
    strcat(err_case, "EMPTY DECIMAL");
  } else {
    (*pos)++;
    answer[*pos] = atof(token);
  }
  *unary_c = 0;
  *oper_c = 0;
}

stack *trigobreaketer(stack *operat, char *token, int *break_c, int *unary_c,
                      int *oper_c) {
  operat = push(operat, token);
  if (*token == '(') {
    (*break_c)++;
    (*unary_c)++;
    *oper_c = 0;
  }
  return operat;
}

stack *backbreaketer(stack *operat, double *answer, int *pos, char *err_case,
                     int *break_c, int *oper_c) {
  int status = OK;
  if (*oper_c) {
    strcat(err_case, "WRONG SEQUENCE");
  } else {
    *oper_c = 0;
    while (operat->value != '(') {
      status = performer(answer, pos, operat->value);
      if (!status) operat = pop(operat);
      if (status || !operat) break;
    }
    (*break_c)--;
    if (*break_c > -1 && !status) {
      if ((operat = pop(operat))) {
        if (operat->value > 96) {
          performer(answer, pos, operat->value);
          operat = pop(operat);
        } else if (operat->value == ')' ||
                   (operat->value > 47 && operat->value < 58)) {
          strcat(err_case, "WRONG SEQUENCE");
        }
      }
    } else {
      strcat(err_case, "MISSED BREAKS");
    }
  }
  return operat;
}

stack *lister(stack *operat, char *token, double *answer, int *pos,
              char *err_case, int *unary_c, int *oper_c) {
  if (*unary_c != 0) {
    if (unary(answer, token, pos, oper_c)) {
      strcat(err_case, "WRONG SEQUENCE");
    } else {
      operat = push(operat, "*");
    }
  } else {
    if (!operat) {
      operat = push(operat, token);
    } else {
      while (operat != NULL && prioritizer(operat, token)) {
        *err_case = performer(answer, pos, operat->value);
        operat = pop(operat);
      }
      operat = push(operat, token);
    }
  }
  (*oper_c)++;
  return operat;
}

int prioritizer(stack *operat, char *token) {
  int swapper = 0;
  int tok_priority = 0;
  if (*token == '+' || *token == '-') {
    tok_priority = 1;
  } else if (*token == '*' || *token == '/' || *token == '%') {
    tok_priority = 2;
  } else if (*token == '^') {
    tok_priority = 3;
  } else {
    tok_priority = 0;
  }
  if (!operat->value) {
    operat->value = *token;
    operat->priority = tok_priority;
  } else if (*token != '(' && (operat->priority >= tok_priority) &&
             tok_priority != 3) {
    swapper = 1;
  }
  return swapper;
}

int performer(double *answer, int *pos, char lexem) {
  int status = OK;
  if (lexem == 's') {
    answer[*pos] = sin(answer[*pos]);
  } else if (lexem == 'c') {
    answer[*pos] = cos(answer[*pos]);
  } else if (lexem == 't') {
    answer[*pos] = tan(answer[*pos]);
  } else if (lexem == 'i') {
    answer[*pos] = asin(answer[*pos]);
  } else if (lexem == 'o') {
    answer[*pos] = acos(answer[*pos]);
  } else if (lexem == 'a') {
    answer[*pos] = atan(answer[*pos]);
  } else if (lexem == 'd') {
    answer[*pos] = log10(answer[*pos]);
  } else if (lexem == 'n') {
    answer[*pos] = log(answer[*pos]);
  } else if (lexem == 'q') {
    answer[*pos] = sqrt(answer[*pos]);
  } else if (lexem == 'e') {
    answer[*pos] = ceil(answer[*pos]);
  } else if (*pos == 0) {
    status = ERROR;
  } else if (lexem == '^') {
    answer[*pos - 1] = pow(answer[*pos - 1], answer[*pos]);
  } else if (lexem == '%') {
    answer[*pos - 1] = fmod(answer[*pos - 1], answer[*pos]);
  } else if (lexem == '/') {
    answer[*pos - 1] = answer[*pos - 1] / answer[*pos];
  } else if (lexem == '*') {
    answer[*pos - 1] = answer[*pos - 1] * answer[*pos];
  } else if (lexem == '-') {
    answer[*pos - 1] = answer[*pos - 1] - answer[*pos];
  } else if (lexem == '+') {
    answer[*pos - 1] = answer[*pos - 1] + answer[*pos];
  }
  if (lexem < 97) {
    answer[(*pos)] = '\0';
    (*pos)--;
  }
  return status;
}

int closerer(stack *operat, double *answer, int *pos, char *err_case) {
  int status = OK;
  if (operat) {
    while (operat != NULL) {
      if (operat->value == '(') {
        strcat(err_case, "MISSED BREAKS");
        break;
      }
      if (!performer(answer, pos, operat->value)) {
        operat = pop(operat);
      } else {
        strcat(err_case, "WRONG SEQUENCE");
      }
    }
  }
  return status;
}

// void cleaner(stack *operat, char *token) {
//   // void cleaner(stack *operat, char *token) {
//   // void cleaner(char *token, stack *operat) {
//   // printf("                                                          free
//   // operat = %p", (void *)operat);
//   if (token != NULL) free(token);
//   if (operat != NULL) free(operat);
// }

// // Copyright 2023 valeryje
