#include <iostream>
#include <vector>
#include <limits>

using std::vector;
using std::min;

int get_change(int m) {
  //write your code here
  vector<int> changes(m+1);
  changes[0] = 0;
  const vector<int> coins = {1,3,4};
  for (int i = 1; i < changes.size(); ++i) {
    changes[i] = std::numeric_limits<int>::max();
    for (int coin : coins) {
        if (i >= coin) {
            int num_coins = changes[i - coin] + 1;
            if (num_coins < changes[i]) {
                changes[i] = num_coins;
            }
            //std::cout << "i= " << i << " coin= " << coin << " num_coins=" << num_coins << " changes[i]=" << changes[i] << "\n";
        }
    }
  }

  return changes[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
