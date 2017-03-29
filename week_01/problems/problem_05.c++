#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
#endif
#include <math.h>
#include <iomanip>

using namespace std;

int main() {
  int a, b, c;

  double total = 0;

  cin >> a >> b >> c;

  total = ((a + b + c) / 2.0) / 3.0;

  cout << fixed << setprecision(6) << total << "\n";

  return 0;
}

