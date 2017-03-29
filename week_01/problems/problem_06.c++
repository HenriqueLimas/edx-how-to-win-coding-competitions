#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
#endif
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <unordered_map>

using namespace std;

typedef unordered_map<char,vector<int>> keyboard;

int distance(keyboard k, char a, char b) {
  vector<int> pos_a = k[a];
  vector<int> pos_b = k[b];

  return max(abs(pos_a[0] - pos_b[0]), abs(pos_a[1] - pos_b[1]));
}

class Language {
  public:
    string name;
    string content;
    int count;
    Language();
    Language(string);
};

Language::Language() {
}
Language::Language(string name) {
  this->name = name;
  this->count = 0;
  this->content = "";
}

int main() {
  int W,H;
  int i,j;

  keyboard k;
  vector<Language> langs (3);

  cin >> W >> H;
  cin.ignore();

  for (i = 0; i < H; i++ ) {
    string keys;

    getline(cin, keys);

    for (j = 0; j < keys.length(); j++) {
      char key = keys[j];

      if (key >= 33 && key <= 126) {
        vector<int> v(2);
        v[0] = i;
        v[1] = j;
        k[key] = v;
      }
    }
  }

  for (i = 0; i < 3;i++) {
    string l_name;
    getline(cin, l_name);

    Language l (l_name);

    string t_start, current_line;
    getline(cin, t_start);

    getline(cin, current_line);

    while(current_line != "%TEMPLATE-END%") {
      for (int c = 0; c < current_line.length(); c++) {
        char key = current_line[c];
        if (key >= 33 && key <= 126) {
          l.content += key;
        }
      }

      getline(cin, current_line);
    }

    langs[i] = l;
  }

  int min_count = INT_MAX;
  Language min_l;

  for (i = 0; i < 3; i++) {
    Language l = langs[i];

    for(j = 0; j < (l.content.length() - 1); j++) {
      l.count += distance(k, l.content[j], l.content[j + 1]);
    }

    if (l.count < min_count) {
      min_count = l.count;
      min_l = l;
    }
  }

  cout << min_l.name << "\n" << min_l.count << "\n";

  return 0;
}
