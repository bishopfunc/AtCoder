#include <bits/stdc++.h>

#include <iomanip>
#include <iostream>

// 図をかく
// 時計回りの回転だからちょっとむずい

using namespace std;
typedef long long ll;

struct pose {
  double x;
  double y;
  double z;
};

double getDist(double diffX, double diffY) {
  return sqrt(diffX * diffX + diffY * diffY);
}
int main() {
  ll T, L, X, Y;
  cin >> T >> L >> X >> Y;
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    double E;
    cin >> E;
    double w = (E / T) * 360 * (M_PI / 180);  // 1/N週 * 360度 *
    pose p = {0, -L / 2.0 * sin(w), L / 2.0 - L / 2.0 * cos(w)};
    double d = getDist(p.x - X, p.y - Y);
    double res = atan(p.z / d) / (M_PI / 180.0);
    cout << fixed << setprecision(12) << res << endl;
    // 俯角はarc tanで計算できる
  }
  // double じゃないと丸め込まれることがある
}