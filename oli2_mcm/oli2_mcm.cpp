#include <cstdio>

int MCD(int a, int b) {
  while (1) {
    if (a < b) {
      int t = b;
      b = a;
      a = t;
    }
    int resto = (a % b);
    if (resto == 0)
      return b;
    a = resto;
  }
}

int main(int argc, char *argv[]) {
  FILE *in = fopen("input.txt", "r"), *out = fopen("output.txt", "w");
  int a, b;
  fscanf(in, "%d %d", &a, &b);
  fprintf(out, "%d\n", a * b / MCD(a, b));

  fclose(in);
  fclose(out);

  return 0;
}
