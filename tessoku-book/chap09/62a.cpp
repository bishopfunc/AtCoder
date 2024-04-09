#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100001
vector<int> G[MAX_N];
bool visited[MAX_N];

// 隣接する未訪問の頂点を再帰的に訪問する
void dfs(int u) {
  visited[u] = true;
  for (int v = 0; v < (int)G[u].size(); v++) {
    if (!visited[G[u][v]]) dfs(G[u][v]);
  }
  return;
}

int main() {
  int N, M;
  cin >> N >> M;
  int a, b;
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    // 1 < a, b < N
    G[a].push_back(b);
    G[b].push_back(a);
  }
  // memset(visited, false, sizeof(visited));
  // memsetはbyte単位で初期化するので、bool型の配列には使えない
  for (int i = 1; i <= N; i++) visited[i] = false;  // visited の初期化
  dfs(1);                                           // 1-indexed
  bool ans = true;
  for (int i = 1; i <= N; i++) {
    if (!visited[i]) {
      ans = false;
      break;
    }
  }
  if (ans) {
    cout << "The graph is connected." << endl;
  } else {
    cout << "The graph is not connected." << endl;
  }
}