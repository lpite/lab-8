#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createFileWithArray() {
  srand(time(0));
  FILE *file;
  file = fopen("j1.txt", "w");

  for (int i = 0; i < 6; i++) {
    for (int i2 = 0; i2 < 9; i2++) {
      int randNum = rand() % 10;
      fprintf(file, "%d", randNum);
    }
    fprintf(file, "\n");
  }
  fclose(file);
}

void readArrayAndSum() {
  FILE *file;
  char a[6][10];
  int sum = 0, r = 1;
  file = fopen("j1.txt", "a+");
  fread(a, sizeof(a), 6, file);
  for (int i = 0; i < 6; i++) {
    for (int i2 = 0; i2 < 9; i2++) {
      printf("%c ", a[i][i2]);
      if (i == i2) {
        r = 0;
      }
      if (r == 1) {
        sum += a[i][i2] - '0';
      }
    }
    r = 1;
    puts("");
  }

  fprintf(file, "sum = %d\n", sum);
  fclose(file);
}

int main() {

  createFileWithArray();
  readArrayAndSum();

  return 0;
}
