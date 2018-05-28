#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::sort;

string largest_number(vector<string> a) {
  //write your code here
  // all we need is to sort strings in decreasing order, i.e 21 must be less than 2
  sort(a.begin(), a.end(), [](const string& s1, const string& s2) {
    return s1 + s2 > s2 + s1;
  });
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
