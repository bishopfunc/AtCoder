#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, L, K;
ll A[100000];
// 0以上のピースは必ず作れる
// L長さ以上のピースは作れない
bool isOK(ll len) {
  int cnt = 0, pre = 0;
  for (int i = 0; i < N; i++) {
    if (A[i] - pre >= len && L - A[i] >= len) {
      cnt++;
      pre = A[i];
    }
  }
  if (cnt >= K) return true;
  return false;
}

int main() {
  cin >> N >> L >> K;
  for (int i = 0; i < N; i++) { cin >> A[i]; }
  ll ok = 0, ng = L;
  // 絶対OKと絶対NGを初期値
  // OK と NG差1になるまで(隣になる)探索
  // 範囲を狭めて最小の条件を探索
  while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    if (isOK(mid)) {
      ok = mid;
    } else {
      ng = mid;
      // 17はNGなので範囲が0-17になって問題ない
    }
  }
  cout << ok << endl;
}

// https://qiita.com/drken/items/97e37dd6143e33a64c8c
// めぐる式すごい