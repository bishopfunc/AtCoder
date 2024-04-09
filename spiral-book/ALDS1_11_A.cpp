#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100

int G[MAX_N + 1][MAX_N + 1] = {};  // 隣接行列

int main() {
  int n;
  cin >> n;
  int u, k, v;
  for (int i = 0; i < n; i++) {
    cin >> u >> k;
    u--;  // 0-indexedに変換
    for (int j = 0; j < k; j++) {
      cin >> v;
      v--;  // 0-indexedに変換
      G[u][v] = 1;  // 0-indexedの隣接行列
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j) cout << " ";
      cout << G[i][j];
    }
    cout << endl;
  }
}