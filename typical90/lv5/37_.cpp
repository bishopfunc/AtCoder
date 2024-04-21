#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF (ll)1e9

// 愚直 O(N*W^2)
// RMQ O(NW + NW*log(W))
// スライド最小値 O(NW)
// AC!
// https://qiita.com/kuuso1/items/318d42cd089a49eeb332

int main() {
  int N, W;
  cin >> W >> N;
  // ll dp[N + 1][W + 1];
  vector<vector<ll>> dp(N + 1, vector<ll>(W + 1, -INF));
  // for (int i = 0; i <= N; i++) {
  //   for (int j = 0; j <= W; j++) { dp[i][j] = -INF; }
  // }

  dp[0][0] = 0LL;  // 商品0 香辛料0 価値0
  // L...R
  // j-R...j-L
  // [i - K + 1, i]なのでOK
  for (int i = 1; i <= N; i++) {
    int L, R;
    ll V;
    cin >> L >> R >> V;
    deque<ll> deq;  // 最大idxの候補
    for (int j = 0; j <= W; j++) {
      // 1. 香辛料なし
      dp[i][j] = dp[i - 1][j];
      // 2. 香辛料あり
      if (j >= L) {
        int idx = j - L;  // 右端からスタート //区間を [idx-R, idx] にしてる
        // 今見てるものより小さいものを外す
        while (!deq.empty() && deq.front() < j - R) { deq.pop_front(); }
        // 区間から外れる
        while (!deq.empty() && dp[i - 1][deq.back()] < dp[i - 1][idx]) {
          deq.pop_back();
        }
        // 今のを追加する
        deq.push_back(idx);
        if (!deq.empty() && dp[i - 1][deq.front()] != -INF) {
          // -INFの条件
          dp[i][j] = max(dp[i - 1][j], dp[i - 1][deq.front()] + V);
        }
      }
    }
  }
  cout << (dp[N][W] == -INF ? -1 : dp[N][W]) << endl;
}