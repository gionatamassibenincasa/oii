#include <cstdio>

int main() {
  FILE *in = fopen("input.txt", "r");
  int N;
  int MAX = -1;
  int a, b, tmp;
  fscanf(in, "%d\n", &N);
  for (int j = 0; j < N; j++) {
    fscanf(in, "%d %d\n", &a, &b);
    tmp = a + b;
    if (tmp % 2 == 0 && tmp > MAX)
      MAX = tmp;
  }

  FILE *out = fopen("output.txt", "w");
  fprintf(out, "%d\n", MAX);
  fclose(out);
  fclose(in);

  return 0;
}
