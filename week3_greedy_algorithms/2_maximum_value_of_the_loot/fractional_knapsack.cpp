#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using std::vector;
using std::sort;
using std::find;
using std::distance;
using std::min;
using std::pair;
using std::make_pair;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  // write your code here
  // create vector of pairs (weight, value)
  vector<pair<int,int>> x;
  for (int i = 0; i < weights.size(); ++i) {
    x.push_back(make_pair(weights[i], values[i]));
  }
  // sort weights in increasing order or v/w
  sort(x.begin(), x.end(), [](const auto& p1, const auto& p2) {
    return static_cast<double>(p1.second) / p1.first < static_cast<double>(p2.second) / p2.first;
  });
  //for (const auto& p : x) {
  //  std::cout << p.first << " ";
  //}
  // fill the knapsack in iteration in decreasing order
  for (int i = x.size() - 1; i >= 0; --i) {
    if (capacity == 0) break;
    int a = min(x[i].first, capacity);
    value += a * static_cast<double>(x[i].second) / x[i].first;
    capacity -= a;
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
