#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 23 // WIDTH must be odd
#define NUMBER_OF_GENERATIONS 10

int decodingRules[] = {
  0, // 000
  1, // 001
  0, // 010
  1, // 011
  1, // 100
  0, // 101
  1, // 110
  0, // 111
};

struct Neighbourhood {
  int leftCell;
  int middleCell;
  int rightCell;
};

int encodeNeighbourhood(struct Neighbourhood neighbourhood) {
  int encoding = 0;

  encoding = encoding + (pow(2, 0) * neighbourhood.rightCell);
  encoding = encoding + (pow(2, 1) * neighbourhood.middleCell);
  encoding = encoding + (pow(2, 2) * neighbourhood.leftCell);

  return encoding;
}

int evolveIndex(int cells[], int index) {
  if (index == 0 || index == WIDTH - 1) {
    return cells[index];
  } else {
    struct Neighbourhood neighbourhood;

    neighbourhood.leftCell = cells[index - 1];
    neighbourhood.middleCell = cells[index];
    neighbourhood.rightCell = cells[index + 1];

    int encoding = encodeNeighbourhood(neighbourhood);
    return decodingRules[encoding];
  }
}

void evolve(int cells[]) {
  int nextGenerationCells[WIDTH];
  int i;

  for (i = 0; i < WIDTH; i = i + 1) {
    int offspring = evolveIndex(cells, i);
    nextGenerationCells[i] = offspring;
  }

  memcpy(cells, nextGenerationCells, sizeof(int) * WIDTH);
}

void printCells(int cells[]) {
  int i;

  for (i = 0; i < WIDTH; i = i + 1) {
    printf("%d", cells[i]);
  }
}

void randomise(int cells[], int length) {
  int i;

  srand(time(NULL));

  for (i = 0; i < length; i = i + 1) {
    if (rand() < RAND_MAX / 2) {
      cells[i] = 1;
    } else {
      cells[i] = 0;
    }
  }
}

int main() {
  int cells[WIDTH];

  randomise(cells, WIDTH);

  int i;

  printCells(cells);

  for (i = 1; i < NUMBER_OF_GENERATIONS; i = i + 1) {
    evolve(cells);
    printCells(cells);
  }

  return 0;
}