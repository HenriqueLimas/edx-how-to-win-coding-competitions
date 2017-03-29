#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
#endif

#include <queue>
#include <deque>

using namespace std;

int main() {
  int n, i;
  queue<int> q;
  deque<int> min_list;
  deque<int>::reverse_iterator rit;

  cin >> n;


  for (i = 0; i < n; i++) {
    char sign;
    int x;

    cin >> sign;

    if (sign == '+') {
      cin >> x;
      q.push(x);

      if (!min_list.empty()) {
        for (rit = min_list.rbegin(); rit != min_list.rend(); ++rit) {
          if (*rit > x) {
            min_list.erase(rit.base());
          } else {
            break;
          }
        }
      }

      min_list.push_back(x);
    } else if (sign == '-') {
      int value_to_remove = q.front();

      q.pop();

      if (value_to_remove == min_list.front()) {
        min_list.pop_front();
      }
    } else {
      int min_value = min_list.front();
      cout << min_value << "\n";
    }
  }

  return 0;
}

