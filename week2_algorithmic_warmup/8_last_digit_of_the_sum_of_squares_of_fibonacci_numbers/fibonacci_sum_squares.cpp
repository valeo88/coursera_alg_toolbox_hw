#include <iostream>
#include <cstdlib>
#include <cassert>
#include <vector>

using std::vector;

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

// use Pisano period pi(m) <= 6 * m and always starts from 01
int get_fibonacci_last_digit_fast(long long n) {

    const int m = 10;

    std::vector<long long> sequence(6 * m);
    sequence[0] = 0;
    sequence[1] = 1;

    int cnt = 1;
    for (long long i = 2; i <= 6 * m; ++i) {
        sequence[i] = (sequence[i-2] + sequence[i-1]) % m;
        ++cnt;
        if (sequence[i-1] == 0 && sequence[i] == 1) {
            // size has 2 elements from next sequence
            cnt -= 2;
            break;
        }
    }

    return sequence[n % cnt];

}

int fibonacci_sum_squares_fast(long long n) {
    // use geometry representation with area of rectangle sum of squares 0 to 5 is F5 * F6
    return get_fibonacci_last_digit_fast(n) * get_fibonacci_last_digit_fast(n + 1) % 10;
}

void test_solution() {
    for (int n = 0; n < 10; ++n) {
        int a = rand() % 50;
        assert(fibonacci_sum_squares_fast(a) == fibonacci_sum_squares_naive(a));
    }
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fast(n);
    //test_solution();
}
