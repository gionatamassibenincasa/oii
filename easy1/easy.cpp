#include <cstdio>

int main() {
  FILE *in = fopen("input.txt", "r");
  FILE *out = fopen("output.txt", "w");
  int N, tmp, MAX = -32000;
  
  fscanf(in, "%d\n", &N);
  
  for (int j = 0; j < N; j++) {
    fscanf(in, "%d", &tmp);
    if (tmp > MAX)
      MAX = tmp;
  }

  fprintf(out, "%d\n", MAX);

  fclose(out);
  fclose(in);

  return 0;
}
