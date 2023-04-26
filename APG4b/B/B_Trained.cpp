#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
int main() {
  int N; cin >> N;
  vector<int> a(N + 1);
  int next = 1, res = -1;
  rep(i, 1, N + 1) cin >> a[i];
  // 回数分シミュレーションする
  rep(i, 1, N + 1) {
    if(a[next] == 2) {
      res = i; //回数を代入
      break;
    }
    next = a[next];
  }
 
  cout << res << endl;
}