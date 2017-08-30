#include <fstream>
#include <iostream>
using namespace std;

int T(int A, int B, int x1, int x2) { return A * x1 + B * x2; }

int solve(int N, int M, int A, int B) {
  int Tmin;
  if (A * M <= B) {
    // la soluzione con x2 e' dominata
    Tmin = T(A, B, N, 0);
  } else {
    // Prova ad inserire tutte le tasse a blocco, anche eccedendo N
    int x2 = (B * (N / M)) + ((N % M) ? 1 : 0);
    int T1 = T(A, B, 0, x2);
    // Simula un B&B che toglie ogni volta un blocco e aggiunge le unità necessarie
    int T2 = T(A, B, N - M * (x2 - 1), x2 - 1);
    int T3 = T(A, B, N - M * (x2 - 2), x2 - 2);
    int T4 = T(A, B, N - M * (x2 - 3), x2 - 3);
    int T5 = T(A, B, N - M * (x2 - 4), x2 - 4);
    Tmin = std::min(T1, T2);
    Tmin = std::min(Tmin, T3);
    Tmin = std::min(Tmin, T4);
    Tmin = std::min(Tmin, T5);
  }

  return Tmin;
}

int main(int argc, char *argv[]) {
  int N, // numero di giorni
      M, // giorni di tasse al costo B
      A, // tassa al giorno
      B; // tassa per M giorni

  /* Modello:
   * min T = A x1 + B x2
   * s.t.
   *           x1 + M x2 >= N
   *
   *           x1, x2 \in N
   *
   *           Il modello ha bound semplificati essendo interi anche T, A e B.
   */

  std::ifstream in("input.txt");
  in >> N >> M >> A >> B;

  std::ofstream out("output.txt");
  out << solve(N, M, A, B) << "\n";

  return 0;
}
