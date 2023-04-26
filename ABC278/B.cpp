#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
int H, M;

bool is_in_24_hours(int h, int m) {
  if (h >= 0 && h <= 23 && m >= 0 && m <= 59) return true;
  return false;
}

bool is_misjudged(int h, int m) {
  int a, b, c, d;
  a = h / 10; b = h % 10;
  c = m / 10; d = m % 10;
  int ac, bd;
  ac = a * 10 + c;
  bd = b * 10 + d;
  // cout << a << b << " " << c << d << endl;
  return is_in_24_hours(ac, bd);
}

int main() {
  cin >> H >> M;
  while (!is_misjudged(H, M)) {
    M++;
    if (M == 60) { M = 0; H++; }
    if (H == 24) H = 0;
  }
  cout << H << " " << M << endl;
}