#include <bits/stdc++.h>

#include "geometry.h"
using namespace std;

int main() {
  int n, q, x, y;
  Point p;
  Polygon g;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    p = Point(x, y);
    g.push_back(p);
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> x >> y;
    p = Point(x, y);
    cout << contains(g, p) << endl;
  }
}