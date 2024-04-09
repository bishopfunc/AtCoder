#include <bits/stdc++.h>
using namespace std;
#define MAX_N 10000
#define INF (ll)1e17
typedef long long ll;
ll dp[MAX_N][MAX_N];
int pre_v[MAX_N][MAX_N];
// jに行く前の頂点 デフォルトはi

// k頂点, i始点, j終点
// kを移動させて i->k->jとi->jを比較

bool is_negative(int V) {
  for (int k = 0; k < V; k++) {
    if (dp[k][k] < 0) return true;
  }
  return false;
}

void warshall_floyd(int V) {
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      pre_v[i][j] = i;
    }
  }

  for (int k = 0; k < V; k++) {
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        // dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        if (dp[i][k] + dp[k][j] < dp[i][j]) {
          dp[i][j] = dp[i][k] + dp[k][j];
          pre_v[i][j] = pre_v[k][j];
        }
      }
    }
  }
}
// 0->1->2->3->4ならreconstruct(0, 4)で[0, 1, 2, 3, 4]を返す
vector<int> reconstruct(int s, int t) {
  vector<int> path;
  if (dp[s][t] == INF) return path;
  path.push_back(t);
  while (t != s) {
    t = pre_v[s][t];
    path.push_back(t);
  }
  path.push_back(s);
  reverse(path.begin(), path.end());
  return path;
}

int main() {
  int s, t, d, V, E;
  cin >> V >> E;
  // 初期化: cost or i==jなら0 or INF
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      dp[i][j] = INF;
      if (i == j) dp[i][j] = 0;
    }
  }
  for (int i = 0; i < E; i++) {
    cin >> s >> t >> d;
    dp[s][t] = d;
  }
  warshall_floyd(V);
  if (is_negative(V))
    cout << "NEGATIVE CYCLE" << endl;
  else {
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        if (j) cout << " ";
        if (dp[i][j] >= INF / 2)  // 2*10^-7<= d <= 2*10^7
          cout << "INF";
        else
          cout << dp[i][j];
      }
      cout << endl;
    }
  }
}