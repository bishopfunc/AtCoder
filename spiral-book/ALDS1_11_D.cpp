#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000
#define MAX_M 100000

enum { UNVISITED, VISITING, VISITED };

vector<int> G[MAX_N] = {};
int groups[MAX_M];
int states[MAX_N];
int group_id = 0;

void dfs(int r) {
  stack<int> S;
  S.push(r);
  states[r] = VISITING;
  while (!S.empty()) {
    int u = S.top();
    S.pop();
    groups[u] = group_id;
    states[u] = VISITED;
    for (int i = 0; i < G[u].size(); i++) {
      int v = G[u][i];
      if (states[v] == UNVISITED) {
        S.push(v);
        states[v] = VISITING;
      }
    }
  }
}

int main() {
  int n, m, s, t;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> s >> t;
    G[s].push_back(t);
    G[t].push_back(s);
  }
  for (int i = 0; i < n; i++) {
    states[i] = UNVISITED;
    groups[i] = -1;
  }
  for (int i = 0; i < n; i++) {
    if (groups[i] == -1) {
      group_id++;
      dfs(i);
    }
  }
  // 深さ優先探索でグループ分け
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> s >> t;
    if (groups[s] == groups[t]) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
}