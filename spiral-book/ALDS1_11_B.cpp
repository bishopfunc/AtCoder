#include <bits/stdc++.h>
using namespace std;
enum { UNVISITED, VISITING, VISITED };

#define MAX_N 100

int G[MAX_N + 1][MAX_N + 1] = {};  // 隣接行列 // 0-indexed
int d[MAX_N] = {};                 // 発見時刻 // 0-indexed
int f[MAX_N] = {};                 // 完了時刻 // 0-indexed
int states[MAX_N] = {};
int t = 1;

void dfs(int r) {
  // 初期化
  stack<int> S;
  d[r] = t++;
  S.push(r);
  states[r] = VISITING;
  while (!S.empty()) {
    bool no_univisited_adjacent = true;
    // 1. スタックのトップを訪問し dに記録 statesをVISITINGに変更
    // 隣接かつ未訪問の頂点をスタックに積む
    int u = S.top();
    for (int v = 0; v < MAX_N; v++) {
      if (G[u][v] && states[v] == UNVISITED) {
        d[v] = t++;
        states[v] = VISITING;
        S.push(v);
        no_univisited_adjacent = false;
        break;
      }
    }
    // 2. 未訪問の頂点がなければスタックから取り出し fに記録
    // statesをVISITEDに変更
    if (no_univisited_adjacent) {
      S.pop();
      f[u] = t++;
      states[u] = VISITED;
    }
    // for (int i = 0; i < 4; i++) {
    //   cout << "states[i]: "<< states[i] << " ";
    //   cout << "d: " << d[i] << " ";
    //   cout << "f: " << f[i] << " ";
    // }
    // cout << endl;
  }
}

int main() {
  int n;
  cin >> n;
  int u, k, v;
  for (int i = 0; i < n; i++) {
    cin >> u >> k;
    u--;  // 0-indexedに変換
    for (int j = 0; j < k; j++) {
      cin >> v;
      v--;          // 0-indexedに変換
      G[u][v] = 1;  // 0-indexedの隣接行列
    }
  }

  for (int i = 0; i < MAX_N; i++) states[i] = UNVISITED;  // 初期化1回
  for (int i = 0; i < n; i++) {
    if (states[i] == UNVISITED) {
      dfs(i);
    }
    // for (int i = 0; i < n; i++) {
    //   cout << i + 1 << " " << d[i] << " " << f[i] << endl;
    // }
  }
  for (int i = 0; i < n; i++) {
    cout << i + 1 << " " << d[i] << " " << f[i] << endl;
  }
}