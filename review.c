// Copyright 2023 valeryje

#include "lib.h"

void checker(const char orig_eq[MAX_LENGTH], char shrt_eq[PARSED_LENGTH],
             const char *x, char *err_case) {
  int len_orig = strlen(orig_eq);  // including '='
  if (len_orig == 1 && orig_eq[len_orig - 1] == '=') {
    strcat(err_case, "EMPTY EQUATION");
  } else if (alienchar(orig_eq, SYMBOLS_EQ)) {
    strcat(err_case, "FORBIDDEN SYMBOLS");
  } else if (len_orig > MAX_LENGTH - 1) {
    strcat(err_case, "EXCEEDED MAX LENGTH");
  } else if (orig_eq[0] == ')' || orig_eq[0] == '^' || orig_eq[0] == '*' ||
             orig_eq[0] == '/' || orig_eq[len_orig - 1] != '=' ||
             orig_eq[len_orig - 2] == '^' || orig_eq[len_orig - 2] == '*' ||
             orig_eq[len_orig - 2] == '/' || orig_eq[len_orig - 2] == '+' ||
             orig_eq[len_orig - 2] == '-' || orig_eq[len_orig - 2] == '(') {
    strcat(err_case, "FREE OPERATOR");
  } else {
    int x_exist = 0;
    int status = 0;
    refiner(orig_eq, shrt_eq, &x_exist, err_case);
    if (!strlen(err_case) && x_exist) status = determ(x, err_case);
    if (!strlen(err_case) && !status) rewriter_x(shrt_eq, x);
  }
}

int alienchar(const char orig_eq[MAX_LENGTH], char *SYMBOLS) {
  int status = OK;
  regex_t pattern;
  regcomp(&pattern, SYMBOLS, (REG_EXTENDED));
  if (REG_NOMATCH == regexec(&pattern, orig_eq, 0, NULL, 0)) status = ERROR;
  regfree(&pattern);
  return status;
}

void refiner(const char orig_eq[MAX_LENGTH], char shrt_eq[PARSED_LENGTH],
             int *x_exist, char *err_case) {
  int skip = 0;
  for (int i = 0, j = 0; i < (int)strlen(orig_eq) - 1; i++, j++) {
    if (orig_eq[i] > 96 && (orig_eq[i] != 'x'))
      if (trigoshortener(orig_eq, shrt_eq, i, j, &skip)) {
        strcat(err_case, "TYPO IN FUNCTION");
        break;
      }
    if (orig_eq[i] == 'x') *x_exist = 1;
    if (skip == 0) shrt_eq[j] = orig_eq[i];
    if ((!(orig_eq[i] > 47 && orig_eq[i] < 58) && orig_eq[i] != '.') ||
        (!(orig_eq[i + 1] > 47 && orig_eq[i + 1] < 58) &&
         orig_eq[i + 1] != '.')) {
      j++;
      shrt_eq[j] = ' ';
    }
    i += skip;
    skip = 0;
  }
}

int trigoshortener(const char orig_eq[MAX_LENGTH], char shrt_eq[PARSED_LENGTH],
                   int i, int j, int *skip) {
  int status = 0;
  if (strncmp(orig_eq + i, "ln(", 3) == 0) {
    shrt_eq[j] = 'n';
    *skip = 1;
  } else if (strncmp(orig_eq + i, "log(", 4) == 0) {
    shrt_eq[j] = 'd';
    *skip = 2;
  } else if (strncmp(orig_eq + i, "mod", 3) == 0) {
    shrt_eq[j] = '%';
    *skip = 2;
  } else if (strncmp(orig_eq + i, "sin(", 4) == 0 ||
             strncmp(orig_eq + i, "cos(", 4) == 0 ||
             strncmp(orig_eq + i, "tan(", 4) == 0) {
    shrt_eq[j] = orig_eq[i];
    *skip = 2;
  } else if (strncmp(orig_eq + i, "sqrt(", 5) == 0) {
    shrt_eq[j] = 'q';
    *skip = 3;
  } else if (strncmp(orig_eq + i, "asin(", 5) == 0) {
    shrt_eq[j] = 'i';
    *skip = 3;
  } else if (strncmp(orig_eq + i, "acos(", 5) == 0) {
    shrt_eq[j] = 'o';
    *skip = 3;
  } else if (strncmp(orig_eq + i, "atan(", 5) == 0) {
    shrt_eq[j] = 'a';
    *skip = 3;
  } else if (strncmp(orig_eq + i, "ceil(", 5) == 0) {
    shrt_eq[j] = 'e';
    *skip = 3;
  }
  if (*skip == 0) status = 1;
  return status;
}

int determ(const char *x, char *err_case) {
  int status = OK;
  if (strlen(x)) {
    if (alienchar(x, SYMBOLS_X)) {
      strcat(err_case, "FORBIDDEN X-SYMBOLS");
    } else {
      if ((strchr(x, '.') != strrchr(x, '.')) ||
          (strchr(x, '-') != strrchr(x, '-'))) {
        status = ERROR;
      } else if (strlen(x) == 2 && x[0] == '-' && x[1] == '.') {
        status = ERROR;
      } else if (strlen(x) == 1 && (x[0] == '-' || x[0] == '.')) {
        status = ERROR;
      } else if (strchr(x, '-') != x && strchr(x, '-') != NULL) {
        status = ERROR;
      }
    }
    if (status) strcat(err_case, "INCORRECT X-NUMBER");
  } else {
    strcat(err_case, "EMPTY X-NUMBER");
  }

  return status;
}

void rewriter_x(char shrt_eq[PARSED_LENGTH], const char *x) {
  int skip = strlen(x);
  if (x[0] == '+' || x[0] == '-') skip = strlen(x) + 5;
  char x_buffer[PARSED_LENGTH] = {0};
  for (int i = 0, j = 0; i < PARSED_LENGTH; i++, j++) {
    if (shrt_eq[j] != 'x') {
      x_buffer[i] = shrt_eq[j];
    } else {
      if (x[0] == '+' || x[0] == '-') {
        for (int k = 0, l = 0; k < skip; k++) {
          if (k == 1 || k == 3 || k == skip - 2) {
            x_buffer[i + k] = ' ';
          } else if (k == 0) {
            x_buffer[i + k] = '(';
          } else if (k == 2) {
            x_buffer[i + k] = x[l];
            l++;
          } else if (k == skip - 1) {
            x_buffer[i + k] = ')';
          } else {
            x_buffer[i + k] = x[l];
            l++;
          }
        }
      } else {
        for (int k = 0; k < skip; k++) x_buffer[i + k] = x[k];
      }
      i += skip - 1;
    }
  }
  for (int i = 0; i < PARSED_LENGTH; i++) shrt_eq[i] = x_buffer[i];
}
