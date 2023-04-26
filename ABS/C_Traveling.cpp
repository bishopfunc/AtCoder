#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------


int main() {
  int N; cin >> N;
  vector<int>t(N + 1, 0);
  vector<int>x(N + 1, 0);
  vector<int>y(N + 1, 0); // 初期値は0を代入しておく
  rep(i, 0, N) cin >> t[i + 1] >> x[i + 1] >> y[i + 1];
  bool res_flag = true;
  
  rep(i, 0, N) {
    int dt = t[i + 1] - t[i];
    int dist = abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i]);
    if (dt < dist) res_flag = false;
    if (dt % 2 != dist % 2) res_flag = false; // 偶奇の一致と長さのみ
  }

  if(res_flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}