#include <iostream>
#include <vector>
#include <cassert>
#include <cstdlib>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

// use Pisano period
int fibonacci_sum_fast(long long n) {

    const int m = 10;

    std::vector<long long> sequence(6 * m);
    sequence[0] = 0;
    sequence[1] = 1;

    int cnt = 1;
    for (int i = 2; i <= 6 * m; ++i) {
        sequence[i] = (sequence[i-2] + sequence[i-1]) % m;
        ++cnt;
        if (sequence[i-1] == 0 && sequence[i] == 1) {
            // size has 2 elements from next sequence
            cnt -= 2;
            break;
        }
    }

    int sum = 0;
    // sum sequence to n % cnt position
    for (int i = 0; i <= n % cnt; ++i) {
        sum += sequence[i];
    }

    return sum % m;

}

void test_solution() {
    for (int n = 0; n < 10; ++n) {
        int a = rand() % 50;
        assert(fibonacci_sum_naive(a) == fibonacci_sum_fast(a));
    }
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
    //test_solution();
}
