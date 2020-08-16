#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 500
#define WHITE_CELL_HTML "<div class='white-cell'></div>"
#define BLACK_CELL_HTML "<div class='black-cell'></div>"

void convertInputToHtml(char *input, char *html) {
  int i;

  for (i = 0; i < strlen(input); i = i + 1) {
    if (input[i] == '0') {
      strcat(html, WHITE_CELL_HTML);
    } 
    if (input[i] == '1') {
      strcat(html, BLACK_CELL_HTML);
    }
  }
}

int main() {
  char input[MAX_INPUT_LENGTH];
  char html[MAX_INPUT_LENGTH * strlen(WHITE_CELL_HTML)];

  if (fgets(input, 500, stdin) == NULL) {
    return 1;
  }

  convertInputToHtml(input, html);

  printf("%s", html);

  return 0;
}