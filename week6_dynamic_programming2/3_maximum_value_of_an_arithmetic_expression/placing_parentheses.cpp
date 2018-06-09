#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <limits>
#include <utility>

using std::vector;
using std::string;
using std::max;
using std::min;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

std::pair<long long,long long> min_and_max(const int i, const int j,
                const vector<vector<long long>>& min_values, const vector<vector<long long>>& max_values,
                const vector<char>& operations) {
    long long min1 = std::numeric_limits<long long>::max();
    long long max1 = std::numeric_limits<long long>::min();
    //std::cout << "i=" << i << " j=" << j << "\n";
    //std::cout << "min: " << min1 << " max: " << max1 << "\n";
    for (int k = i; k < j; ++k) {
        long long a = eval(max_values[i][k], max_values[k+1][j], operations[k-1]);
        long long b = eval(max_values[i][k], min_values[k+1][j], operations[k-1]);
        long long c = eval(min_values[i][k], max_values[k+1][j], operations[k-1]);
        long long d = eval(min_values[i][k], min_values[k+1][j], operations[k-1]);
        //std::cout << "a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        min1 = min(min1, min(a, min(b, min(c,d))));
        max1 = max(max1, max(a, max(b, max(c,d))));
        //std::cout << "k=" << k <<" min: " << min1 << " max: " << max1 << "\n";
    }
    return std::make_pair(min1, max1);
}

long long get_maximum_value(const string &exp) {
  //write your code here
  vector<long long> operands;
  vector<char> operations;
  for (int i = 0; i < exp.size(); ++i) {
    if (i % 2 == 0) {
        operands.push_back((long long)exp[i]);
    } else {
        operations.push_back(exp[i]);
    }
  }
  const size_t n = operands.size();
  // 2d vectors for max and min values
  vector<vector<long long>> min_values(n+1, vector<long long>(n+1));
  vector<vector<long long>> max_values(n+1, vector<long long>(n+1));
  // fill diagonals with elements
  for (int i = 1; i <= n; ++i) {
    min_values[i][i] = std::stoll(std::string(1, operands[i-1]));
    max_values[i][i] = std::stoll(std::string(1, operands[i-1]));
  }
  for (int s = 1; s < n; ++s) {
    for (int i = 1; i <= n - s; ++i) {
        int j = i + s;
        auto mM = min_and_max(i,j,min_values,max_values,operations);
        min_values[i][j] = mM.first;
        max_values[i][j] = mM.second;
    }
  }
  return max_values[1][n];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
