#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

int MaxPairwiseProductNaive(const vector<int>& numbers) {
  int result = 0;
  int n = numbers.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (numbers[i] * numbers[j] > result) {
        result = numbers[i] * numbers[j];
      }
    }
  }
  return result;
}

void Swap(int& a, int& b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int Partition(vector<int>& a, int l, int r) {
    int v = a[(l + r) / 2];
    int i = l;
    int j = r;
    while (i <= j) {
        while (a[i] < v) {
            ++i;
        }
        while (a[j] > v) {
            --j;
        }
        if (i >= j) {
            break;
        }
        Swap(a[i++], a[j--]);
    }
    return j;
}

// quick sort http://neerc.ifmo.ru/wiki/index.php?title=%D0%91%D1%8B%D1%81%D1%82%D1%80%D0%B0%D1%8F_%D1%81%D0%BE%D1%80%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%BA%D0%B0
void Sort(vector<int>& numbers, int l, int r) {
    if (l < r) {
        int q = Partition(numbers, l, r);
        Sort(numbers, l, q);
        Sort(numbers, q + 1, r);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    // user quick sort
    Sort(numbers, 0, n - 1);
    // product can be very big
    int64_t product = static_cast<int64_t>(numbers[n - 1]) * numbers[n - 2];

    cout << product << "\n";
    return 0;
}
