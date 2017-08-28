#include <cstdio>

int main(int argc, char *argv[]) {
  int n;
  FILE *in = fopen("input.txt", "r"), *out = fopen("output.txt", "w");
  fscanf(in, "%d", &n);
  int val[n + 1]; // g++ lo accetta ed e' efficiente
  bool vis[n + 1];

  for (int j = 1; j <= n; j++) {
    fscanf(in, "%d", &(val[j]));
    vis[j] = false;
  }

  int pos = 1;
  int nv = n - 1;
  vis[1] = true;
  while (1) {
    pos = (pos + val[pos]) % n + 1;
    if (vis[pos])
      break;
    vis[pos] = true;
    nv--;
  }

  fprintf(out, "%d\n", nv);
  for (int j = 1; j <= n; j++)
    if (!vis[j])
      fprintf(out, "%d ", j);
  fputs("\n", out);

  fclose(in);
  fclose(out);

  return 0;
}
