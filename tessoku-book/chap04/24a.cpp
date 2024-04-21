// LIS 最長増加部分列問題

// DP + 二分探索
// セグ木 + DP + 座標圧縮

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF (ll)1e9

// 添字と値を逆にするテクニック
// dp[i][w] = v
// i番目のものまで見て、重さの総和がw以下になるように選んだ価値の総和の最大値
// dp[i][v] = w
// i番目のものまで見て、価値の総和がv以上になる商品を選んだ時、重さの総和の最小値

// dp[i][w]

// dp[i][j] i番目(Ai)まで見て、最後の要素がAj、の最長の部分列数
// dp[j] 最後の要素がAj、の最長の部分列数 in-place N^2
// dp[i][k] i番目(Ai)まで見て、部分列数がkの、最小のAj
// dp[k] 部分列数がkの、最小のAj in-place
// dp[2]=2 dp[2]=4 はあり得ない
// dp[1]=1 dp[2]=2 dp[3]=5 でA=4のとき、dp[2]=4 A=4のとき、dp[2]=4

// dp[k] 長さkの部分列を作る最後の数字
// 条件を満たす部分列は必ず前より大きい
// 2 3 1 6 4 5
// 小さい方が後ろが長く作れて良い
// 4で6をdp[2]上書きするが、次が4の場合dp[2]、5の場合dp[2]、
// A=5の時、5よりちょうど小さいやつの長さ+1

// https://qiita.com/drken/items/68b8503ad4ffb469624c
int main() {
  int N;
  cin >> N;
  vector<int> dp(N, INF);
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    int k = lower_bound(dp.begin(), dp.end(), A) - dp.begin();
    dp[k] = A;  // 長さk-1が正しい
  }
  int min_len = lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
  // INF以上がある最小のidx do[0]~do[N-1]が埋まってるので
  // ちょうどINFを満たすIDがNになる
  cout << min_len << endl;
}