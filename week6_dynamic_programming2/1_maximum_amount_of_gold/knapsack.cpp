#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  const int n = w.size();
  vector<vector<int>> value(W+1, vector<int>(n+1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= W; ++j) {
        // value[j][i-1] - max value for i-1 elements
        value[j][i] = value[j][i-1];
        // need to use i - 1 because indexes in w are 0...n-1
        if (w[i-1] <= j) {
            // value of gold piece is its weight
            int val = value[j - w[i-1]][i-1] + w[i-1];
            if (value[j][i] < val) {
                value[j][i] = val;
            }
        }
    }
  }
  return value[W][n];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
