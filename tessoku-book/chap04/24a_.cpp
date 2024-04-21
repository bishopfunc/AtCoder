// LIS 最長増加部分列問題

// DP + 二分探索
// セグ木 + DP + 座標圧縮
#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;

// dp[h] 最後の要素がhの時の最長の部分列数
// 0~A の最大値を取得 max
// dp[A] = len + 1 update

int op(int a, int b) { return max(a, b); }
int e() { return 0; }

int main() {
  int N;
  cin >> N;

  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  // 座標圧縮
  vector<int> T = A;
  sort(T.begin(), T.end());
  T.erase(unique(T.begin(), T.end()), T.end());
  // for (int i = 0; i < N; i++) {
  // B[i] = lower_bound(T.begin(), T.end(), A[i]) - T.begin();
  // cout << B[i] << endl;
  // }
  segtree<int, op, e> dp(N);  // 単位元で初期化 N分

  int ans = 0;
  for (int i = 0; i < N; i++) {
    int h = lower_bound(T.begin(), T.end(), A[i]) - T.begin();
    // 同じ値を削除済み配列TでA[i]のidxを決める
    int len = dp.prod(0, h);  // (0, h-1] vs h これまでvs今
    // B[i]はA[i]がAのi番目にあるか 2なら
    // [0, 3)の最長を取得->len=1 [3, 4)をlen=2に更新
    // cout << len << endl;
    if (dp.get(h) < len + 1) {
      dp.set(h, len + 1);
      ans = max(ans, len + 1);
    }
  }
  cout << ans << endl;
}