#include <bits/stdc++.h>

#include "geometry.h"
using namespace std;

int main() {
  int x, y;
  Point p1, p2, p;
  Segment s;
  for (int i = 1; i <= 2; i++) {
    cin >> x >> y;
    if (i == 1) p1 = Point(x, y);
    if (i == 2) p2 = Point(x, y);
  }
  s = Segment(p1, p2);

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> x >> y;
    p = Point(x, y);
    Point res = project(s, p);
    cout << fixed << setprecision(10) << res.x << " " << res.y << endl;
  }
}
