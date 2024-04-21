#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int G[201][201], C[201][201];
bool visited[201];
int H, W;

void bfs(int s) {
  queue<int> q;
  q.push(s);
  visited[s] = true;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u = 1; u <= H; u++) {
      if (G[v][u] == 1 && !visited[u]) {
        visited[u] = true;
        //
        q.push(u);
      }
    }
  }
}
int main() {
  cin >> H >> W;
  int s_i, s_j, g_i, g_j;
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      C[i][j] = 0;
    }
  }
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      string a;
      cin >> a;
      if (a == ".")
        G[i][j] == 1;
      else if (a == "#")
        G[i][j] == 0;
      else if (a == "S") {
        G[i][j] = 1;
        s_i = i;
        s_j = j;
      } else if (a == "T") {
        G[i][j] = 1;
        g_i = i;
        g_j = j;
      }
    }
  }

  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int R, C, E;
    cin >> R >> C >> E;
  }
}