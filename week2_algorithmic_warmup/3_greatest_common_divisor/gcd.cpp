#include <iostream>
#include <cassert>
#include <cstdlib>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_euclid(int a, int b) {
    // implementing Euclid algorithm to find GCD
    if (a < b) {
        int _tmp = 0;
        _tmp = b;
        b = a;
        a = _tmp;
    }
    if (b == 0) return a;
    // recursive call
    gcd_euclid(b, a % b);
}

void test_solution() {
    for (int n = 0; n < 10; ++n) {
        int a = rand() % 10000;
        int b = rand() % 10000;
        assert(gcd_naive(a, b) == gcd_euclid(a, b));
    }
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_euclid(a, b) << std::endl;
  //test_solution();
  return 0;
}
