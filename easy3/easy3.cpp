#include <cstdio>

struct massimi {
  size_t minimo;
  int massimi[2];
} pari = {0, {-1, -1}}, dispari = pari;

int main(int argc, char **argv) {
  FILE *in = fopen("input.txt", "r"), *out = fopen("output.txt", "w");
  int n, p = -1, d = -1;
  fscanf(in, "%d\n", &n);

  for (int j = 0; j < n; j++) {
    int v;
    fscanf(in, "%d", &v);
    if (v % 2 == 0) { // pari
      if (v > pari.massimi[pari.minimo]) {
        int altro = (pari.minimo + 1) % 2;
        pari.massimi[pari.minimo] = v;
        if (pari.massimi[altro] < v)
          pari.minimo = altro;
      }
    } else { // dispari
      if (v > dispari.massimi[dispari.minimo]) {
        int altro = (dispari.minimo + 1) % 2;
        dispari.massimi[dispari.minimo] = v;
        if (dispari.massimi[altro] < v)
          dispari.minimo = altro;
      }
    }
  }
  if (pari.massimi[pari.minimo] != -1)
    p = pari.massimi[0] + pari.massimi[1];
  if (dispari.massimi[dispari.minimo] != -1)
    d = dispari.massimi[0] + dispari.massimi[1];
  if (p > d)
    fprintf(out, "%d\n", p);
  else
    fprintf(out, "%d\n", d);

  return 0;
}
