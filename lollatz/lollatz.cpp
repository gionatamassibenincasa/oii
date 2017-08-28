#include <assert.h>
#include <stdio.h>

int afaikdiyrotfl(int N) {
  int prev = N;
  for (;;) {
    // printf("%d\t", N);
    int cifra = N % 10;
    if (cifra == 0)
      return N;
    N *= cifra - 1;
    // printf("x 3 = %d\t", N);
    N /= 2;
    // printf("/2 3 = %d\n", N);
    if (N == prev)
      return -1;
    prev = N;
  }
}

int main() {
  FILE *fr, *fw;
  int N;

  fr = fopen("input.txt", "r");
  fw = fopen("output.txt", "w");
  assert(1 == fscanf(fr, "%d", &N));

  fprintf(fw, "%d\n", afaikdiyrotfl(N));
  fclose(fr);
  fclose(fw);
  return 0;
}
