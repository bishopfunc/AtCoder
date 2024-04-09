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
  Polygon res = andrewScan(g);
  cout << res.size() << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i].x << " " << res[i].y << endl;
  }
}