#include <iostream>
#include <vector>

using std::vector;
using std::max;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  //write your code here
  const size_t n = a.size();
  const size_t m = b.size();
  const size_t k = c.size();
  int l[n+1][m+1][k+1];
  // iterate over 3 vectors from the start of it
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
        for (int p = 0; p <= k; ++p) {
            if (i == 0 || j == 0 || p == 0) {
                // first row and first column are zero
                l[i][j][p] = 0;
            } else if (a[i-1] == b[j-1] && a[i-1] == c[p-1]) {
                // current elements is equal - add to subsequence lenght
                l[i][j][p] = l[i-1][j-1][p-1] + 1;
            } else {
                // current elements is not equal - calc max of subsequences without first element and second element
                const int m1 = max(l[i-1][j][p], l[i][j-1][p]);
                const int m2 = max(l[i][j][p-1], l[i][j-1][p-1]);
                const int m3 = max(l[i-1][j-1][p], l[i-1][j][p-1]);
                l[i][j][p] = max(m1, max(m2, m3));
            }
            //std::cout << l[i][j] << " ";
        }
    }
    //std::cout << "\n";
  }
  return l[n][m][k];
  //return std::min(std::min(a.size(), b.size()), c.size());
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
