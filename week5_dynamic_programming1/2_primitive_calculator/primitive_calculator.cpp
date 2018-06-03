#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using std::vector;
using std::min;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

// with dynamic programming
vector<int> optimal_sequence_dp(int n) {
  std::vector<int> sequence;
  // count min steps for every number from 1 to n
  std::vector<int> steps(n+1);
  steps[1] = 0;
  steps[2] = 1;
  steps[3] = 1;
  for (int i = 4; i < steps.size(); ++i) {
    int i_div_3 = std::numeric_limits<int>::max();
    int i_div_2 = std::numeric_limits<int>::max();
    int i_minus_1 = steps[i - 1] + 1;
    if (i % 3 == 0) {
        i_div_3 = steps[i/3] + 1;
    }
    if (i % 2 == 0) {
        i_div_2 = steps[i/2] + 1;
    }
    // find minimum steps count for i
    steps[i] = min(i_minus_1, min(i_div_3, i_div_2));
  }
  // decrease n using info from steps
  while (n > 0) {
    sequence.push_back(n);
    if(n % 2 == 0 && n % 3 != 0) {
        if (steps[n-1] < steps[n/2]) {
            n--;
        } else {
            n /= 2;
        }
    } else if(n % 2 != 0 && n % 3 == 0) {
        if(steps[n-1] < steps[n/3]) {
            n--;
        } else {
            n /= 3;
        }
    } else if (n % 2 == 0 && n % 3 == 0) {
        if (steps[n/3] <= steps[n/2] && steps[n/3] <= steps[n-1]) {
            n /= 3;
        } else if (steps[n/2] <= steps[n/3] && steps[n/2] <= steps[n-1]) {
            n /= 2;
        } else {
            n--;
        }
    } else if (n % 2 != 0 && n % 3 != 0) {
        n--;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence_dp(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
