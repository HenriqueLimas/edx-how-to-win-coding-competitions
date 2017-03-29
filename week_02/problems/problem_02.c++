#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
#endif

#include <queue>

using namespace std;

int main() {
  int n, i;
  queue<int> q;

  cin >> n;

  for (i = 0; i < n; i++) {
    char sign;
    int x;

    cin >> sign;

    if (sign == '+') {
      cin >> x;
      q.push(x);
    } else {
      cout << q.front() << "\n";
      q.pop();
    }
  }

  return 0;
}

