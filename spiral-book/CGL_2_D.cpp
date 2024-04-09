#include <bits/stdc++.h>

#include "geometry.h"
using namespace std;

int main() {
  int n;
  cin >> n;
  int x, y;
  Point p0, p1, p2, p3;
  Segment s0, s1;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    p0 = Point(x, y);
    cin >> x >> y;
    p1 = Point(x, y);
    cin >> x >> y;
    p2 = Point(x, y);
    cin >> x >> y;
    p3 = Point(x, y);
    s0 = Segment(p0, p1);
    s1 = Segment(p2, p3);
    cout << fixed << setprecision(10) << getDistanceSS(s0, s1) << endl;
  }
}