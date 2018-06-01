#include <iostream>
#include <vector>

using std::vector;

long long merge_with_count(vector<int>& b, vector<int>& c, size_t left, size_t mid, size_t right) {
    long long number_of_inversions = 0;
    size_t i = left;
    size_t j = mid;
    size_t last_idx = left;

    while (i < mid && j < right) {
        if (b[i] <= b[j]) {
            c[last_idx++] = b[i++];
        } else {
            c[last_idx++] = b[j++];
            /*At any step in merge_with_count(), if b[i] is greater than c[j], then there are (mid – i) inversions.
             because left and right subarrays are sorted, so all the remaining elements in left-subarray (b[i+1], b[i+2] … b[mid]) will be greater than b[j] */
            number_of_inversions += mid - i;
        }
    }
    // move rest to c
    while (i < mid) {
        c[last_idx++] = b[i++];
    }
    while (j < right) {
        c[last_idx++] = b[j++];
    }

    return number_of_inversions;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  //write your code here
  // fucking ave + 1 need use
  number_of_inversions += merge_with_count(a, b, left, ave + 1, right);

  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());

  std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
  //for (int x : b) {
  //  std::cout << x << " ";
  //}
}
