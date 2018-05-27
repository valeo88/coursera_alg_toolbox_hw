#include <iostream>

int get_change(int m) {
  //we have coins with denominations of 1,5,10
  // need to find minimum of coins to change m value of money
  // for the first move we need to use maximum possible denom coin
  const int coin_denoms[] = {10,5,1};
  int cnt = 0;
  for (int i = 0; i < 3; ++i) {
    if (m < coin_denoms[i]) {
        continue;
    } else {
        const int reminder = m % coin_denoms[i];
        cnt += (m - reminder) / coin_denoms[i];
        m = reminder;
        if (m == 0) {
            break;
        }
    }
  }

  return cnt;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
