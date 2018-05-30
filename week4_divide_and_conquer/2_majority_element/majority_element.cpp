#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  // split vector in the middle
  int half_size = (right - left) / 2;
  int mid = left + half_size;
  // get majority elements of each part of the vector
  int b = get_majority_element(a, left, mid);
  int c = get_majority_element(a, mid, right);
  //std::cout <<  "mid = " << mid << ": b = " << b << " c = " << c << "\n";
  // if elements is equal - we don't need to count it
  if (b == c) return b;

  // count numbers of b and c in this part of vector a
  int count_b = std::count(a.begin()+left, a.begin()+right, b);
  int count_c = std::count(a.begin()+left, a.begin()+right, c);

  // we need to select only potential majority element, i.e. count > half_size of current part of vector a
  // becase if exists majority element, then exist parts of vector when it's major
  if (count_b > half_size) {
    return b;
  } else if (count_c > half_size) {
    return c;
  } else {
    return -1;
  }
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
