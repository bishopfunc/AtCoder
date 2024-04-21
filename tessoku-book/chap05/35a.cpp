#include <bits/stdc++.h>
using namespace std;

// dp[i][j] 最善手を選んだ時のスコア i段目j個目
// 最後の段は固定
// 上から 1 2 3 4 ..
// 偶数 先手 奇数 後手
// N=4の時 3step 0-2 A B A
// N=5の時 4step 0-3 A B A B
// 偶数先手でOK
// 最善じゃない可能性を省いてる
// 3段目のどこでも、取る行動は決まってる = 点数を書いて 最小の選択肢を省く矢印
// 2段目のどこでも、とる行動は決まってる = 点数を書いて 最大の選択肢を省く矢印

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  int dp[N][N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    dp[N - 1][i] = A[i];
  }

  // 下から上にシミュレーション
  for (int i = N - 2; i >= 0; i--) {
    for (int j = 0; j <= i; j++) {  // j<=i 3段目は3個
      // cout << "i: " << i << ", j: " << j << endl;
      // cout << "dp[i+1][j]: " << dp[i + 1][j] << ", dp[i+1][j+1]: " << dp[i +
      // 1][j+1] << endl; 偶数段目は先手
      if (i % 2 == 0) dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]);
      // 左 i+1,j 右 i+1,j+1
      else dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]);
    }
  }
  cout << dp[0][0] << endl;  // てっぺんに答え
}
