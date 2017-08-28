#include <cassert>
#include <cmath>
#include <cstdio>

bool primo(int a) {
  int radq = sqrt(a);
  for (int d = 2; d <= radq; d++)
    if (a % d == 0)
      return false;
  return true;
}

int semiprimo(int N, int *a, int *b) {
  int radq = sqrt(N);
  for (int d = 2; d <= radq; d++) {
    if (N % d == 0) {
      // d e' il divisore piu' piccolo
      if (!primo(d)) {
        return false;
      }
      *b = N / d;
      if (primo(*b)) {
        *a = d;
        return true;
      } else {
        return false;
      }
    }
  }
  return false;
}

int main() {
  FILE *fr, *fw;
  int N, a, b;

  fr = fopen("input.txt", "r");
  fw = fopen("output.txt", "w");
  assert(1 == fscanf(fr, "%d", &N));

  if (semiprimo(N, &a, &b))
    fprintf(fw, "%d %d\n", a, b);
  else
    fputs("-1\n", fw);
  fclose(fr);
  fclose(fw);
  return 0;
}
