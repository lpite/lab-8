#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void createTextFile() {
  FILE *file;
  file = fopen("words.txt", "w");
  fprintf(file,
          "in vitae turpis massa sed elementum tempus egestas sed sed risus "
          "pretium quam vulputate dignissim suspendisse in est ante in nibh "
          "mauris cursus mattis molestie a iaculis at erat pellentesque "
          "adipiscing commodo elit at imperdiet dui accumsan sit amet nulla "
          "facilisi morbi tempus iaculis urna id volutpat lacus laoreet non");
  fclose(file);
}

void task() {
  FILE *file;
  file = fopen("words.txt", "r+");
  fseek(file, 0, SEEK_END);
  int size = ftell(file);
  fseek(file, 0, SEEK_SET);
  char *str = malloc(sizeof(char) * size);
  fread(str, sizeof(char), size, file);
  char *tok = NULL, *sav = NULL;
  tok = strtok_s(str, " ", &sav);
  while (tok != NULL) {
    printf("\"%s\" ", tok);
    tok = strtok_s(NULL, " ", &sav);
  }
  // printf("size = %d\n", size);
  // printf("str = %s\n", str);
}

int main() {
  createTextFile();
  task();
  return 0;
}