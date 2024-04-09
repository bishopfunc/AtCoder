#include <bits/stdc++.h>

#include "geometry.h"
using namespace std;

int main() {
  int n;
  cin >> n;
  int x, y;
  Point p0, p1, p2, p3;
  Vector v0, v1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> x >> y;
      if (j == 0) p0 = Point(x, y);
      if (j == 1) p1 = Point(x, y);
      if (j == 2) p2 = Point(x, y);
      if (j == 3) p3 = Point(x, y);
    }
    v0 = p1 - p0;
    v1 = p3 - p2;
    if (isParallel(v0, v1))
      cout << 2 << endl;
    else if (isOrthogonal(v0, v1))
      cout << 1 << endl;
    else
      cout << 0 << endl;
  }
}