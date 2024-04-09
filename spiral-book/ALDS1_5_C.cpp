#include <bits/stdc++.h>

#include <iomanip>
using namespace std;

struct Point {
    double x, y;
};

void koch(int n, Point p1, Point p2) {
    Point s, t, u;
    if (n == 0) return;
    double th = M_PI * 60.0 / 180.0;
    s.x = (2.0 * p1.x + 1.0 * p2.x) / 3.0;
    s.y = (2.0 * p1.y + 1.0 * p2.y) / 3.0;
    t.x = (1.0 * p1.x + 2.0 * p2.x) / 3.0;
    t.y = (1.0 * p1.y + 2.0 * p2.y) / 3.0;
    u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
    u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;
    koch(n - 1, p1, s);
    cout << setprecision(12) << s.x << " " << s.y << endl;
    koch(n - 1, s, u);
    cout << setprecision(12) << u.x << " " << u.y << endl;
    koch(n - 1, u, t);
    cout << setprecision(12) << t.x << " " << t.y << endl;
    koch(n - 1, t, p2);
}

int main() {
    int n;
    cin >> n;
    Point p1, p2;
    p1.x = 0.0;
    p1.y = 0.0;
    p2.x = 100.0;
    p2.y = 0.0;
    cout << setprecision(12) << p1.x << " " << p1.y << endl;
    koch(n, p1, p2);
    cout << setprecision(12) << p2.x << " " << p2.y << endl;
}
