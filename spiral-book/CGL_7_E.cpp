#include <bits/stdc++.h>

#include "geometry.h"
using namespace std;

int main() {
  int x, y, r;
  cin >> x >> y >> r;
  Circle c1 = Circle(Point(x, y), r);
  cin >> x >> y >> r;
  Circle c2 = Circle(Point(x, y), r);
  vector<Point> res = getCrossPointCC(c1, c2);
  sort(res.begin(), res.end());
  for (int i = 0; i < res.size(); i++) {
    cout << fixed << setprecision(10);
    if (i) cout << " ";
    cout << res[i].x << " " << res[i].y;
  }
  cout << endl;
}