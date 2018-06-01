#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <tuple>

using std::vector;
using std::sort;

struct Point {
  int number;
  size_t idx; // index in initial array
  char type;
};

bool operator<(const Point& lhs, const Point& rhs) {
    return std::make_tuple(lhs.number, lhs.type) < std::make_tuple(rhs.number, rhs.type);
}


vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  //write your code here
  vector<Point> p;
  for (auto x : starts) {
    p.push_back({x, 0, 'l'});
  }
  for (auto x : ends) {
    p.push_back({x, 0, 'r'});
  }
  for (int i = 0; i < points.size(); ++i) {
    p.push_back({points[i], i, 'p'});
  }
  // sort vector of Points
  sort(p.begin(), p.end());
  /*(2,l),(3,p),(4,l),(5,p),(6,r),(8,p),(10,r)
  Now, let's scan it from left to right. The first item indicates the beginning of a segment (as it has l).
 The next is a point and we know that it is covered by one segment.
 The next item (4,l) indicates that we have the second segment.
 The next item (5,p) is a point and it is covered by two segments.
 The next item indicates the end of some segment. And so on.
   */
  int seg_starts = 0;
  int seg_ends = 0;
  //std::cout << "Points: ";
  for (const Point& el : p) {
    if (el.type == 'l') {
        seg_starts++;
    } else if (el.type == 'r') {
        seg_ends++;
    } else {
        cnt[el.idx] = seg_starts - seg_ends;
    }
    //std::cout << "(" << el.number << ", " << el.type << ") ";
  }
  //std::cout << "\n";

  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

void test_solution() {
    for (int n = 0; n < 10; ++n) {
        int s = rand() % 10 + 1;
        int p = rand() % 10 + 1;
        vector<int> starts(s), ends(s);
        vector<int> points(p);
        for (int i = 0; i < s; ++i) {
            int start = rand() % 100;
            int end = rand() % 100 + start;
            starts[i] = start;
            ends[i] = end;
        }
        for (int i = 0; i < p; ++i) {
            int point1 = rand() % 100;
            int point2 = - (rand() % 100);
            points[i] = point1 + point2;
        }
        //std::cout << a << " " << b << "\n";
        std::cout << "s = " << s << " p = " << p << "\n";
        std::cout << "segments: ";
        for (int i = 0; i < s; ++i) {
            std::cout << "[" << starts[i] << "," << ends[i] << "] ";
        }
        std::cout << "\n";
        std::cout << "points: ";
        for (int i = 0; i < p; ++i) {
            std::cout << points[i] << " ";
        }
        std::cout << "\n";
        std::cout << "Naive: ";
        vector<int> naive_cnt = naive_count_segments(starts, ends, points);
        for (int x : naive_cnt) {
            std::cout << x << " ";
        }
        std::cout << "\n";
        std::cout << "Fast: ";
        vector<int> fast_cnt = fast_count_segments(starts, ends, points);
        for (int x : fast_cnt) {
            std::cout << x << " ";
        }
        std::cout << "\n";
        assert(naive_cnt == fast_cnt);
        std::cout << "\n";
    }
}


int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  //vector<int> cnt = naive_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
  //test_solution();
}
