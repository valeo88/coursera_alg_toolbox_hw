#include <iostream>
#include <vector>

using std::vector;
using std::max;

int lcs2(vector<int> &a, vector<int> &b) {
  //write your code here
  const size_t n = a.size();
  const size_t m = b.size();
  int l[n+1][m+1];
  // iterate over 2 vectors from the start of it
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
        if (i == 0 || j == 0) {
            // first row and first column are zero
            l[i][j] = 0;
        } else if (a[i-1] == b[j-1]) {
            // current elements is equal - add to subsequence lenght
            l[i][j] = l[i-1][j-1] + 1;
        } else {
            // current elements is not equal - calc max of subsequences without first element and second element
            l[i][j] = max(l[i][j-1], l[i-1][j]);
        }
        //std::cout << l[i][j] << " ";
    }
    //std::cout << "\n";
  }
  return l[n][m];
  //return std::min(std::min(a.size(), b.size()), c.size());
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
