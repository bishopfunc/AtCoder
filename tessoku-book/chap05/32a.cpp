#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100001
bool dp[MAX_N];

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  // iは残りi個の状態を表す
  // i=0~Nをdpで計算し、dp[N]、つまり初手が答え
  // 勝ちの状態はtrue
  fill(dp, dp + MAX_N, false);
  for (int i = 0; i <= N; i++) {
    if (i >= A && dp[i - A] == false)
      dp[i] = true;
    else if (i >= B && dp[i - B] == false)
      dp[i] = true;
    else
      dp[i] = false;  // 0,1の時は負け状態;
  }
  cout << (dp[N] ? "First" : "Second") << endl;
}