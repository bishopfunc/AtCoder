#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX_M 100001
// 彩色問題
// 木は必ず2部グラフらしい
//
// color -1 0 1

vector<int> G[MAX_M];
int color[MAX_M];
void dfs(int v, int c) {
  // cout << "v: " << v << endl;
  color[v] = c;
  for (auto& u : G[v]) {
    if (color[u] != -1) continue;
    dfs(u, 1 - c);
  }
}

int main() {
  int N;
  cin >> N;
  fill(color, color + MAX_M, -1);
  for (int i = 0; i < N - 1; i++) {
    int A, B;
    cin >> A >> B;
    A--;
    B--;
    // 1-index
    G[A].push_back(B);
    G[B].push_back(A);
  }
  dfs(0, 0);
  vector<int> g0, g1;

  // 多い方はN/2以上
  for (int i = 1; i <= N; i++) {
    if (color[i] == 0) g0.push_back(i + 1);
    else if (color[i] == 1) g1.push_back(i + 1);
  }
  if (g0.size() > g1.size()) {
    for (int i = 0; i < (N / 2); i++) {
      if (i) cout << " ";
      cout << g0[i];
    }

  } else {
    for (int i = 0; i < (N / 2); i++) {
      if (i) cout << " ";
      cout << g1[i];
    }
    cout << endl;
  }
}