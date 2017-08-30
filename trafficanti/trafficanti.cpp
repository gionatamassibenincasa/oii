#include <cmath>
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>

/*
  Lunghezza della stringa S: s
  Lunghezza della stringa che contiese S: k

  Tutte le stringhe di lunghezza k che contengono la stringa di lunghezza s sono:
                   -
                  | 1,                               se k == s
  tutte (s, k) = <  (k-s+1) * 10^(k-s),              se k < 2s
                  | (k-s+1) * 10^(k-s) - f (s, k-s), se k >= 2s
                   -

Es, k == s:

  k == s => S

Es, k < 2 * s:

  k == s => {S}
  k == s + 1 => {{xS}, {Sx}}
  k == s + 2 => {{xxS}, {xSx}, {Sxx}}
  .    .   .
  k == s + s - 1 {{x*S}, ..., {Sx*}}

Es, k == 2s
  {...} - {{SS} = f(s, s)}

Es, k == 2s + 1
  {...} - {{xSS} - {SxS} - {SSx} == {f (s, s + 1)}}

Es, k = 3s
  {{XxX}, {xSx}, {Sxx}}  - xSS -

*/




long long int potenza_in_modulo(int base, int esponente, int m) {
	if (esponente == 1)
		return base % m;
	return ((base % m) * potenza_in_modulo(base, esponente - 1, m) % m) % m;
}

long long int prodotto_modulo(long long a, long long b, long long m) {
	return ((a % m) * (b % m)) % m;
}

long long int f(int s, int k, long long int m) {
  // caso base banale
  if (s == k)
    return 1;
  // caso base
  int exp = k - s;
  int coef = exp + 1;
  if (k < 2 * s) {
    return prodotto_modulo(coef, potenza_in_modulo(10, exp, m), m);
  }
  // caso ricorsivo
  // calcola il numero di parole contenti la sottostringa, con ripetizioni
  long long int sstr_con_rip = prodotto_modulo(coef, potenza_in_modulo(10, exp, m), m);
  // calcola il numero di ripetizioni, in modulo
  long long int rip = f(s, k - s, m);
  long long int res = (sstr_con_rip - rip) % m;
  if (res < 0)
	  res = m + res;

  return res;
}

int main(int argc, char *argv[]) {
  const long long int m = 1000000007;
  std::ifstream in("input.txt");
  std::string S;
  int K;
  in >> K;
  in >> S;

  int l = S.size();

  long long int res = f(l, K, m);
  std::ofstream out("output.txt");
  out << res << std::endl;

  return 0;
}

