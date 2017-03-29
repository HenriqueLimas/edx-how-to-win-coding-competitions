#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif
#include <stdlib.h>

int main() {
  int i;
  int n;
  int p_max, t_max;

  cin >> n;

  if (n < 2) {
    cout << n;
    return 0;
  }

  int total = 0;
  int total_p = 0;
  int total_t = 0;

  int p[n], t[n];
  int MIN_DIFF = 10000;

  for (i = 0; i < n; i++) {
    cin >> p[i];
    total_p += p[i];
  }

  for (i = 0; i < n; i++) {
    cin >> t[i];
    total_t += t[i];
    int diff = abs(p[i] - t[i]);

    if (p[i] > t[i]) {
      total += p[i];
    } else {
      total += t[i];
    }

    if (diff < MIN_DIFF) MIN_DIFF = diff;
  }

  if (total_p == total || total_t == total) {
    total -= MIN_DIFF;
  }

  cout << total << "\n";

  return 0;
}
