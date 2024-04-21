#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100000

// 木DP
vector<int> G[MAX_N];  // 上司->部下
int dp[MAX_N + 1];     // 社員Aの部下の数

int main() {
  int N, a;
  cin >> N;
  for (int i = 2; i <= N; i++) {
    cin >> a;
    G[a].push_back(i);
  }
  for (int u = N; u >= 1; u--) {
    dp[u] = 0;
    for (auto v : G[u]) {
      dp[u] += dp[v] + 1;
      // 絶対>1の時実行される, 部下0なら+1されない
    }
  }
  for (int i = 1; i <= N; i++) {
    if (i > 1) cout << " ";
    cout << dp[i];
  }
  cout << endl;
}