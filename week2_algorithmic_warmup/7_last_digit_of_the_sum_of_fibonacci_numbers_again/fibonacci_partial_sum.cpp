#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>

using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

// use Pisano period
int get_fibonacci_partial_sum_fast(long long from, long long to) {

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
    for (int i = from % cnt; i <= to % cnt; ++i) {
        sum += sequence[i];
    }

    return sum % m;

}

void test_solution() {
    for (int n = 0; n < 10; ++n) {
        int a = rand() % 50;
        int b = rand() % 40;
        assert(get_fibonacci_partial_sum_naive(b, a) == get_fibonacci_partial_sum_fast(b, a));
    }
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
    //test_solution();
}
