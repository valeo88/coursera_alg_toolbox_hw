#include <iostream>
#include <vector>
#include <cassert>
#include <cstdlib>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

// use Pisano period pi(m) <= 6 * m and always starts from 01
long long get_fibonacci_huge_fast(long long n, long long m) {
    if (m <= 1)
        return m;

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

void test_solution() {
    for (int n = 0; n < 10; ++n) {
        int a = rand() % 50;
        int b = rand() % 10 + 1;
        std::cout << a << " " << b << "\n";
        assert(get_fibonacci_huge_fast(a, b) == get_fibonacci_huge_naive(a, b));
    }
}


int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
    //test_solution();
}
