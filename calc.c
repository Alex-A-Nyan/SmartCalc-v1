// Copyright 2023 valeryje

#include "lib.h"

// int main() {
//   const char *orig_eq = "(8)+x+1-x+3=";
//   const char x[255] = "63.23-42343";
//   char *ans = smartcalc(orig_eq, x);
//   free(ans);
//   return 0;
// }

char *smartcalc(const char *orig_eq, const char *x) {
  char *answer = calloc(500, sizeof(char));
  char shrt_eq[PARSED_LENGTH];
  memset(shrt_eq, 0, PARSED_LENGTH);
  checker(orig_eq, shrt_eq, x, answer);
  if (!*answer) processor(shrt_eq, answer);
  return answer;  // сделать free на фронте
}
