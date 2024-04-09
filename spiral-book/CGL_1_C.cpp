#include <bits/stdc++.h>

#include "geometry.h"
using namespace std;

int main() {
  int x, y;
  Point p0, p1, p2, res;
  Segment s;
  for (int i = 1; i <= 2; i++) {
    cin >> x >> y;
    if (i == 1) p0 = Point(x, y);
    if (i == 2) p1 = Point(x, y);
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> x >> y;
    p2 = Point(x, y);
    switch (ccw(p0, p1, p2)) {
      case COUNTER_CLOCKWISE:
        cout << "COUNTER_CLOCKWISE" << endl;
        break;
      case CLOCKWISE:
        cout << "CLOCKWISE" << endl;
        break;
      case ONLINE_BACK:
        cout << "ONLINE_BACK" << endl;
        break;
      case ONLINE_FRONT:
        cout << "ONLINE_FRONT" << endl;
        break;
      case ON_SEGMENT:
        cout << "ON_SEGMENT" << endl;
        break;
      default:
        break;
    }
  }
}
