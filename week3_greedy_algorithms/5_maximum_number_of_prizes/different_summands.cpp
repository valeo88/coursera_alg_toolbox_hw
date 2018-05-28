#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  int sum = 0;
  int prev = 0;
  int i = 1;
  while (sum < n) {
    if (i > prev && (n - (sum + i)) > i) {
        // we can iterate to next
        summands.push_back(i);
        sum += i;
        prev = i;
    } else {
        // no available numbers
        summands.push_back(n - sum);
        break;
    }
    ++i;
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
