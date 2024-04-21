#include <bits/stdc++.h>

#include <iomanip>
using namespace std;
typedef long long ll;
typedef long double ld;

// https://qiita.com/ganyariya/items/adef1a7f89ae88b804da
// https://nebocco.hatenablog.com/entry/2021/11/13/185816
// https://ngtkana.hatenablog.com/entry/2021/11/13/202103

struct Point {
  ld x, y;
};

Point operator-(const Point& p1, const Point& p2) {
  return Point{p2.x - p1.x, p2.y - p1.y};
};

const ld RAD_TO_DEG = (ld)180.0 / M_PI;

// atan2 [pi,-pi]-> [0,2pi]
ld argument(Point p) {
  // ld argz = atan2l(p.y, p.x) * RAD_TO_DEG;
  // if (argz < 0) argz += (ld)360.0;
  ld argz = acosl(p.x / sqrtl(p.x * p.x + p.y * p.y)) * RAD_TO_DEG;
  if (p.y < 0) argz = 360.0 - argz;
  return argz;
}

// 240 - 30 = 150
// 180 - 30 = 150
ld arg_diff(ld arg1, ld arg2) {
  ld diff = abs(arg2 - arg1);
  if (diff >= (ld)180.0) return (ld)360.0 - diff;
  return diff;
}

ld get_max_arg(vector<Point> points) {
  int N = points.size();
  ld ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        if (i == j || j == k || i == k) continue;
        ld arg1 = argument(points[j] - points[i]);
        ld arg2 = argument(points[k] - points[i]);
        ans = max(ans, arg_diff(arg1, arg2));
      }
    }
  }
  return ans;
}

vector<Point> arg_sort(vector<Point>& points) {
  sort(points.begin(), points.end(), [](const Point& p1, const Point& p2) {
    return atan2l(p1.y, p1.x) < atan2l(p2.y, p2.x);
  });
  return points;
}

// 点のリスト、中心にしたい点、その点のindex
ld solve(vector<Point> points, Point p, int idx) {
  int N = points.size();
  vector<Point> diff_points;
  for (int i = 0; i < N; i++) {
    if (i == idx) continue;
    diff_points.push_back(points[i] - p);
    // 同じidは追加しない
  }
  // vector<Point> sorted_points = arg_sort(diff_points);
  vector<ld> argzs;
  for (int i = 0; i < N; i++) {
    argzs.push_back(argument(diff_points[i]));
    cout << diff_points[i].x << ", ";
    cout << diff_points[i].y << endl;
    cout << argzs[i] << endl;
  }
  sort(argzs.begin(), argzs.end());
  // 偏角リストの中から順番に二分探索
  int len = argzs.size();
  ld max_argz = 0.0;
  for (int i = 0; i < len; i++) {
    // 始点を小さく調節
    ld theta = argzs[i] + (ld)180.0;
    if (theta >= (ld)360.0) theta -= (ld)360.0;
    // cout << argzs[i] << ", ";
    // cout << theta << endl;

    int pos = lower_bound(argzs.begin(), argzs.end(), theta) - argzs.begin();
    // posがNの場合は0にしたい pos-1が最適の場合もある
    int pos1 = pos % len;
    int pos2 = (pos - 1 + len) % len;
    max_argz = max(max_argz, arg_diff(argzs[pos1], theta));
    max_argz = max(max_argz, arg_diff(argzs[pos2], theta));
  }
  return max_argz;
}

int main() {
  int N;
  cin >> N;
  vector<Point> P(N);
  for (int i = 0; i < N; i++) cin >> P[i].x >> P[i].y;
  ld ans = 0.0;
  // 中心点を決めて探索
  for (int i = 0; i < N; i++) {
    cout << "p: " << P[i].x << ", " << P[i].y << endl;
    ans = max(ans, solve(P, P[i], i));
  }

  cout << fixed << setprecision(12);
  cout << ans << endl;
}