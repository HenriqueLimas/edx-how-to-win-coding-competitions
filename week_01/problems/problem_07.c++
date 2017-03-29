#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
#endif
#include <stdlib.h>
#include <math.h>

using namespace std;

int divisor_count(long long n) {
  int len = sqrt(n);
  int count = 0;

  for (int i = 1; i <= len; i++) {
    if (n % i == 0) {
      if ((n/i) == i) {
        count++;
      } else {
        count += 2;
      }
    }
  }

  return count;
}

int main() {
  long long k, max_num;
  int max_divisor = 0;

  cin >> k;

  for (long long i = 0; i <= k; i++) {
    int current_count = divisor_count(i);

    if (current_count > max_divisor) {
      max_divisor = current_count;
      max_num = i;
    }
  }

  cout << k - max_num + 1;

  return 0;
}
