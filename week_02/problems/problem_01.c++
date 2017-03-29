#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
#endif

#include <stack>

using namespace std;

int main() {
  int n, i;
  stack<int> s;

  cin >> n;

  for (i = 0; i < n; i++) {
    char sign;
    int x;

    cin >> sign;

    if (sign == '+') {
      cin >> x;
      s.push(x);
    } else {
      cout << s.top() << "\n";
      s.pop();
    }
  }

  return 0;
}

