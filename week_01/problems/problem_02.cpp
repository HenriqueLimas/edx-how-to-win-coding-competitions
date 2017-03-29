#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif

int main() {
  long long a, b;
  long long total;

  cin >> a >> b;
  total = a + (b * b);
  cout << total << "\n";

  return 0;
}
