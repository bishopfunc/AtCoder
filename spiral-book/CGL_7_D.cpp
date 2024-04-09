#include <bits/stdc++.h>

#include "geometry.h"
using namespace std;

int main() {
  int q, x, y, r;
  cin >> x >> y >> r;
  Circle c = Circle(Point(x, y), r);
  Line l;
  cin >> q;
  for (int i = 0; i < q; i++) {
    Point p1, p2;
    cin >> x >> y;
    p1.x = x;
    p1.y = y;
    cin >> x >> y;
    p2.x = x;
    p2.y = y;
    l = Line(p1, p2);
    vector<Point> res = getCrossPointCL(c, l);
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
      cout << fixed << setprecision(10);
      if (i) cout << " ";
      cout << res[i].x << " " << res[i].y;
    }
    cout << endl;
  }
}