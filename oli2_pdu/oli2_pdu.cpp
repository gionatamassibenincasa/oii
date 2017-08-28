#include <cstdio>

int main(int argc, char **argv) {
  FILE *in = fopen("input.txt", "r"), *out = fopen("output.txt", "w");
  int n, p = 0, d = 0;
  fscanf(in, "%d\n", &n);

  for (int j = 0; j < n; j++) {
    int v;
    fscanf(in, "%d", &v);
    if (v % 2 == 0) { // pari
      p += v;
    } else { // dispari
      d += v;
    }
  }
  if (p == d)
    fputs("U\n", out);
  else if (p > d)
    fputs("P\n", out);
  else
    fputs("D\n", out);

  return 0;
}
