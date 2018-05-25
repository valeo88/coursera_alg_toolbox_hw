#include <iostream>
#include <cassert>
#include <cstdlib>

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

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long lcm_fast(int a, int b) {
    // use fact than a * b / gcd(a,b) is lcm of a and b
    int gcd = gcd_euclid(a, b);
    return ((long long) a) * b / gcd;
}

void test_solution() {
    for (int n = 0; n < 10; ++n) {
        int a = rand() % 10000;
        int b = rand() % 10000;
        assert(lcm_fast(a, b) == lcm_naive(a, b));
    }
}



int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  //test_solution();
  return 0;
}
