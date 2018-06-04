#include <iostream>
#include <string>

using std::string;
using std::min;

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  const size_t n = str1.size();
  const size_t m = str2.size();
  // create matrix n x m
  int d[n+1][m+1];
  // fill zero row and zero column
  for (int i = 0; i <= m; ++i) {
    d[0][i] = i;
  }
  for (int i = 0; i <= n; ++i) {
    d[i][0] = i;
  }
  // iterate over strings
  for (int j = 1; j <= m; ++j) {
    for (int i = 1; i <= n; ++i) {
        const int ins = d[i][j-1] + 1;
        const int del = d[i-1][j] + 1;
        const int match = d[i-1][j-1];
        const int mis_match = d[i-1][j-1] + 1;
        if (str1[i-1] == str2[j-1]) {
            d[i][j] = min(ins,min(del, match));
        } else {
            d[i][j] = min(ins,min(del, mis_match));
        }
        //std::cout << d[i][j] << " ";
    }
    //std::cout << "\n";
  }
  return d[n][m];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
