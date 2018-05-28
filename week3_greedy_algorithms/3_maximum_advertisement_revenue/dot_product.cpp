#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::sort;

// total running time is O(n log n) = O (n log n) of sorting + O (n) of iterate
long long max_dot_product(vector<int> a, vector<int> b) {
  // write your code here
  long long result = 0;
  // sort a and b vector - O(n log n)
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  // sum of products of max elements or step-by-step - O (n)
  for (size_t i = 0; i < a.size(); ++i) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
