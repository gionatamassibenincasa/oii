#include <cstdio>

int main(int argc, char **argv) {
  FILE *in = fopen("input.txt", "r"), *out = fopen("output.txt", "w");
  int n, len = 1;
  fscanf(in, "%d", &n);

  for (; n != 1; len++) {
    if (n % 2 == 0) { // pari
      n /= 2;
    } else { // dispari
      n *= 3, ++n;
    }
  }

  fprintf(out, "%d\n", len);

  return 0;
}
