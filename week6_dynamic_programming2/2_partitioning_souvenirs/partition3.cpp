#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using std::vector;
using std::make_tuple;
using std::tuple;

tuple<int,vector<int>> optimal_weight(int W, const vector<int> &w) {
  const int n = w.size();
  vector<vector<int>> value(W+1, vector<int>(n+1));
  // elements used to fill knapsack
  vector<vector<vector<int>>> used(W+1, vector<vector<int>>(n+1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= W; ++j) {
        // value[j][i-1] - max value for i-1 elements
        value[j][i] = value[j][i-1];
        used[j][i] = used[j][i-1];
        // need to use i - 1 because indexes in w are 0...n-1
        if (w[i-1] <= j) {
            // value of gold piece is its weight
            int val = value[j - w[i-1]][i-1] + w[i-1];
            vector<int> used_val = used[j - w[i-1]][i-1];
            used_val.push_back(w[i-1]);
            if (value[j][i] < val) {
                value[j][i] = val;
                used[j][i] = used_val;
            }
        }
    }
  }
  //std::sort(used[W].begin(), used[W].end());
  return make_tuple(value[W][n], used[W][n]);
}

int partition3(vector<int> &A) {
  //write your code here
  const int n = A.size();
  if (n < 3) {
    return 0;
  }
  // calc sum of souveniers prices
  const int sum = std::accumulate(A.begin(), A.end(), 0);
  if (sum % 3 != 0) {
    return 0;
  }
  // value of each part of souveniers
  const int part_value = sum / 3;
  for (int i = 1; i <= 3; ++i) {
    // sort in descending orber i don't understand why
    std::sort(A.rbegin(), A.rend());
    auto res = optimal_weight(part_value, A);
    if (std::get<0>(res) != part_value) {
        return 0;
    }
    // remove used elements from vector A
    for (int u : std::get<1>(res)) {
        auto it = find(A.begin(), A.end(), u);
        A.erase(it);
    }
  }
  return 1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
