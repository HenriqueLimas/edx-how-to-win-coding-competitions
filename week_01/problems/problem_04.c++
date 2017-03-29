#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
#endif
#include <math.h>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

bool desc(int a, int b) {
  return a > b;
}

int main() {
  int i, j;
  double total = 0;

  vector<double> t_a(6);
  int p[3][3];

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      cin >> p[i][j];
    }
  }

  for (i = 0; i < 3; i++) {
    int a = i;
    int b, c;

    switch (a) {
      case 0:
        b = 1;
        c = 2;
        t_a[0] = pow(p[0][a], 2) + pow(p[1][b], 2) + pow(p[2][c], 2);
        t_a[1] = pow(p[0][a], 2) + pow(p[1][c], 2) + pow(p[2][b], 2);
        break;
      case 1:
        b = 0;
        c = 2;
        t_a[2] = pow(p[0][a], 2) + pow(p[1][b], 2) + pow(p[2][c], 2);
        t_a[3] = pow(p[0][a], 2) + pow(p[1][c], 2) + pow(p[2][b], 2);
        break;
      case 2:
        b = 0;
        c = 1;
        t_a[4] = pow(p[0][a], 2) + pow(p[1][b], 2) + pow(p[2][c], 2);
        t_a[5] = pow(p[0][a], 2) + pow(p[1][c], 2) + pow(p[2][b], 2);
        break;
    }
  }

  sort(t_a.begin(), t_a.end(), desc);

  cout << fixed << setprecision(6) << sqrt(t_a[0]) << "\n";

  return 0;
}
