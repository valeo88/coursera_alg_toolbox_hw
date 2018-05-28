#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;
using std::sort;
using std::max;
using std::min;

struct Segment {
  int start, end;
};

// total running time is O(n log n)
vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  // sort segments - O(n log n)
  sort(segments.begin(), segments.end(), [](const Segment& s1, const Segment& s2) {
    if (s1.start < s2.start) {
        return true;
    } else if (s1.start == s2.start) {
        return s1.end < s2.end;
    }
    return false;
  });
  // we need to get vector of disjoint segments and than get for 1 any point from every segment
  // first safe move is calc joint of first two segments because we already sort them
  // running time is O (n)
  vector<Segment> segments_jointed;
  Segment s_joint = segments[0]; // segment for max joint of segment sequence - first segment
  for (size_t i = 1; i < segments.size(); ++i) {
    const Segment& curr = segments[i];
    //std::cout << "Current: " << curr.start << " - " << curr.end;
    //std::cout << "Jointed: " << s_joint.start << " - " << s_joint.end;
    const int joint_start = max(curr.start, s_joint.start);
    const int joint_end = min(curr.end, s_joint.end);
    //std::cout << "Joint with current: " << joint_start << " - " << joint_end;
    if (joint_start > joint_end) {
        // no joint - push last
        segments_jointed.push_back(s_joint);
        s_joint = curr;
    } else {
        s_joint.start = joint_start;
        s_joint.end = joint_end;
    }
  }
  segments_jointed.push_back(s_joint); // if all segments is jointed
  // select any point from vector of disjointed segments
  for (size_t i = 0; i < segments_jointed.size(); ++i) {
    points.push_back(segments_jointed[i].end);
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
