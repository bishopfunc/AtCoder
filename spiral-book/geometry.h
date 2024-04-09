// geometry.h
#include <bits/stdc++.h>

#include <iomanip>
#include <iostream>
using namespace std;
#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)
#define NIL -1

// struct Point {
//   double x, y;
// };

class Point {
 public:
  double x, y;
  Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}
  Point operator+(Point p) { return Point(x + p.x, y + p.y); }
  Point operator-(Point p) { return Point(x - p.x, y - p.y); }
  Point operator*(double a) { return Point(a * x, a * y); }
  Point operator/(double a) { return Point(x / a, y / a); }

  bool operator==(const Point& p) const {
    return equals(x, p.x) && equals(y, p.y);
  }
  bool operator<(const Point& p) const { return x != p.x ? x < p.x : y < p.y; };
  bool operator>(const Point& p) const { return x != p.x ? x > p.x : y > p.y; };
  // xが等しくないときはxで比較、等しいときはyで比較
};

typedef Point Vector;
typedef vector<Point> Polygon;
class Segment {
 public:
  Point p1, p2;
  Segment(Point p1 = Point(), Point p2 = Point()) : p1(p1), p2(p2) {}
};

typedef Segment Line;

class Circle {
 public:
  Point c;
  double r;
  Circle(Point c = Point(), double r = 0.0) : c(c), r(r) {}
};
// メンバ変数c, rを初期化する

typedef vector<Point> Polygon;

double dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }

double cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }

double norm(Vector a) { return a.x * a.x + a.y * a.y; }

double abs(Vector a) { return sqrt(norm(a)); }

// 外積が0なら平行
bool isParallel(Vector a, Vector b) { return equals(cross(a, b), 0.0); }

// 内積が0なら直交
bool isOrthogonal(Vector a, Vector b) { return equals(dot(a, b), 0.0); }

// 射影
// 線分sに対する点pの射影
Point project(Segment s, Point p) {
  Vector base = s.p2 - s.p1;
  Vector hypo = p - s.p1;
  double t = dot(hypo, base) / abs(base);
  // ベクトルhypoをベクトルbaseに射影したベクトルの長さ
  double r = t / abs(base);
  // 射影部分とbaseの長さの比
  return s.p1 + base * r;
}

// 反射
// 線分sを軸に点pを反射
// 射影からpまでのベクトルを2倍したものを足す
Point reflect(Segment s, Point p) { return p + (project(s, p) - p) * 2.0; }

// Counter Clockwise
// 3点の位置関係
enum Position {
  COUNTER_CLOCKWISE = 1,
  CLOCKWISE = -1,
  ONLINE_BACK = 2,
  ONLINE_FRONT = -2,
  ON_SEGMENT = 0
};

int ccw(Point p0, Point p1, Point p2) {
  Vector a = p1 - p0;
  Vector b = p2 - p0;
  if (cross(a, b) > EPS) return COUNTER_CLOCKWISE;  // 反時計回りなら外積が正
  if (cross(a, b) < -EPS) return CLOCKWISE;  // 時計回りなら外積が負
  if (dot(a, b) < -EPS) return ONLINE_BACK;  // 180度内積が-1 * N
  if (abs(a) < abs(b)) return ONLINE_FRONT;  // 180度内積が1 * N
  return ON_SEGMENT;
}

// 線分s1と線分s2の交差判定
// p1p2に対してp3p4が反対側にある、かつp3p4に対してp1p2が反対側にある
// 時計回り1、反時計回り-1、直線0
// A * B が正ならばAとBは同じ側にある、負ならば反対側にある
bool intersect(Segment s1, Segment s2) {
  Point p1 = s1.p1, p2 = s1.p2, p3 = s2.p1, p4 = s2.p2;
  return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
          ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

// 点a, bの距離
double getDistancePP(Point a, Point b) { return abs(a - b); }

// 点pと直線lの距離
// d = |axb| / |a|
// 外積(平行四辺形の面積) ÷ 底辺 = 高さ
double getDistanceLP(Segment s, Point p) {
  Vector a = s.p2 - s.p1;
  Vector b = p - s.p1;
  return abs(cross(a, b)) / abs(a);
}

// 点pと線分sの距離
// 直線と同じ場合か、端点との距離の小さい方
// > 90 つまり内積が < 0
double getDistanceSP(Segment s, Point p) {
  if (dot(s.p2 - s.p1, p - s.p1) < 0.0) return abs(p - s.p1);
  if (dot(s.p1 - s.p2, p - s.p2) < 0.0) return abs(p - s.p2);
  return getDistanceLP(s, p);
}

// 線分s1と線分s2の距離
double getDistanceSS(Segment s1, Segment s2) {
  if (intersect(s1, s2)) return 0.0;
  return min({getDistanceSP(s1, s2.p1), getDistanceSP(s1, s2.p2),
              getDistanceSP(s2, s1.p1), getDistanceSP(s2, s1.p2)});
}

// 外積 / 底辺 = 高さ
// 高さの比 = 底辺の比 d1 : d2 = t : 1 - t
Point crossPoint(Segment s1, Segment s2) {
  Vector base = s2.p2 - s2.p1;
  double d1 = abs(cross(base, s1.p1 - s2.p1)) / abs(base);
  double d2 = abs(cross(base, s1.p2 - s2.p1)) / abs(base);
  double t = d1 / (d1 + d2);
  return s1.p1 + (s1.p2 - s1.p1) * t;
}

// 円cと直線lの交点
vector<Point> getCrossPointCL(Circle c, Line l) {
  Point pr = project(l, c.c);  // 円心から直線に射影した点
  Vector e = (l.p2 - l.p1) / abs(l.p2 - l.p1);  // 直線の単位ベクトル
  double base = sqrt(c.r * c.r - norm(pr - c.c));
  // 円の半径と射影した点と円の中心の距離 base^2 + h^2 = r^2
  vector<Point> res = {pr - e * base, pr + e * base};
  return res;
}

// 極座標形式で角度と半径から点を求める
Vector polar(double theta, double r) {
  return Vector(cos(theta) * r, sin(theta) * r);
}

// 円c1と円c2の交点
// 余弦定理 cosα = (a^2 + b^2 - c^2) / 2ab
// atan2(y, x) = ArcTan(y / x)
vector<Point> getCrossPointCC(Circle c1, Circle c2) {
  double d = abs(c1.c - c2.c);
  double cosTheta = (d * d + c1.r * c1.r - c2.r * c2.r) / (2 * d * c1.r);
  double theta = acos(cosTheta);  // r1とdのなす角
  Vector v = c2.c - c1.c;         // c1からc2へのベクトル
  double phi = atan2(v.y, v.x);   // x軸からの角度
  vector<Point> res = {c1.c + polar(phi + theta, c1.r),
                       c1.c + polar(phi - theta, c1.r)};
  return res;
}

enum Contain {
  IN = 2,
  ON = 1,
  OUT = 0,
};
// 多角形の内外判定
// ベクトルaは g_iとpのベクトル ベクトルbは g_i+1とpのベクトル
// 辺の上にある = 平行四辺形を作れないため、外積が0 かつ
// 反対方向のベクトだから、内積が負
// 点pから右方向に伸ばした直線と多角形の辺との交点の数を数える
// 内部にある = 交点が奇数個
// 外部にある = 交点が偶数個
// 交差判定は aとbが直線の両側にあるかどうかで判定 かつ aとbがpの右側にある
// aとbがpの右側にある = 外積が正 = aからbに向かうと反時計回り
// aとbがpの左側にある = 外積が負 = aからbに向かうと時計回り
// 前提としてaはbより下にある
int contains(Polygon g, Point p) {
  int n = g.size();
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    Point a = g[i] - p, b = g[(i + 1) % n] - p;
    if (abs(cross(a, b)) < EPS && dot(a, b) < EPS) return ON;
    if (a.y > b.y) swap(a, b);
    if (a.y < EPS && EPS < b.y && cross(a, b) > EPS) cnt++;
    // a.y * b.y < -EPS はダメ
  }
  return (cnt % 2 == 0) ? OUT : IN;
}

bool compare(Point a, Point b) { return a.y != b.y ? a.y < b.y : a.x < b.x; }
bool compareRev(Point a, Point b) { return a.y != b.y ? a.y > b.y : a.x > b.x; }

// 凸包を求めるアルゴリズム
// 2個前の点と今見てる点g[i]、1個前の点と今見てる点g[i]、のCCWが時計回りなら、凸を作る、push_back
// そうでないなら、凸を作らない、pop_back
Polygon andrewScan(Polygon g) {
  Polygon u, l;  // 凸包の上部と下部
  if (g.size() < 3) return g;

  // 凸包の上部を作る 最低2点は入れる
  sort(g.begin(), g.end(), compare);  // x座標で昇順にソート
  for (int i = 0; i < g.size(); i++) {
    cout << g[i].x << " " << g[i].y << endl;
  }

  u.push_back(g[0]);
  u.push_back(g[1]);
  for (int i = 2; i < g.size(); i++) {
    int n = u.size();
    while (n >= 2 && ccw(u[n - 2], u[n - 1], g[i]) == COUNTER_CLOCKWISE) {
      u.pop_back();
      n--;
    }
    u.push_back(g[i]);
  }

  // 凸包の下部を作る 最低2点は入れる
  sort(g.begin(), g.end(), compareRev);  // x座標で降順にソート

  // 演算子 > をオーバーロードしている
  l.push_back(g[0]);
  l.push_back(g[1]);
  for (int i = 2; i < g.size(); i++) {
    int n = l.size();
    while (n >= 2 && ccw(l[n - 2], l[n - 1], g[i]) == COUNTER_CLOCKWISE) {
      l.pop_back();
      n--;
    }
    l.push_back(g[i]);
  }

  Polygon res;
  // 反時計回り
  sort(u.begin(), u.end(), compareRev);
  sort(l.begin(), l.end(), compare);
  // cout << "u" << endl;
  // for (int i = 0; i < u.size(); i++) cout << u[i].x << " " << u[i].y << endl;
  // cout << "l" << endl;
  // for (int i = 0; i < l.size(); i++) cout << l[i].x << " " << l[i].y << endl;

  u.pop_back();
  l.pop_back();

  // 凸包の上部と下部を合わせる 上部の最後の点と下部の最後の点は重複している
  for (int i = 0; i < l.size(); i++) res.push_back(l[i]);
  for (int i = 0; i < u.size(); i++) res.push_back(u[i]);

  return res;
}
