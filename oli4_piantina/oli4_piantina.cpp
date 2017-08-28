#include <cstdio>

int main(int argc, char *argv[]) {
  FILE *in = fopen("input.txt", "r"), *out = fopen("output.txt", "w");
  int min, max, primo, ultimo;
  fscanf(in, "%d %d", &min, &max);
  int j;
  for (j = 1; j <= 1000; j++) {
    int quadrato = j * j;
    if (quadrato >= min) {
      primo = j;
      break;
    }
  }
  for (; j <= 1000; j++) {
    int quadrato = j * j;
    if (quadrato == max) {
      ultimo = j;
      break;
    } else if (quadrato > max) {
      ultimo = j - 1;
      break;
    }
  }

  fprintf(out, "%d\n", ultimo - primo + 1);

  return 0;
}
