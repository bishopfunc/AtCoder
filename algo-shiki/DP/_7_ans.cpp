#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1<<29; // 十分大きい値にする, INT_MAX にしないのはオーバーフロー対策

// 入力
int N, M;
int A[510], B[510]; 

// DPテーブル
int dp[510][10010]; 

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; ++i) cin >> A[i] >> B[i];

  // 一旦すべて INF に
  for (int i = 0; i < N + 1; ++i) for (int j = 0; j < M +1; ++j) dp[i][j] = INF;
  dp[0][0] = 0;                // dp[0][0] だけ 0 に

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j <= M; ++j) {
      if (dp[i][j] != INF) dp[i+1][j] = 0;
      if (j >= A[i]) {
        if (dp[i][j-A[i]] != INF) {
            chmin(dp[i+1][j], 1);
        }
        if (dp[i+1][j-A[i]] < B[i]) {
            chmin(dp[i+1][j], dp[i+1][j-A[i]] + 1); 
        }
      }
    }
  }

  if (dp[N][M] != INF) cout << "Yes" << endl;  
  else cout << "No" << endl; 
}