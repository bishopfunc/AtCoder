#include <bits/stdc++.h>
using namespace std;
#define MAX_E 100000
#define MAX_V 10001

#define NIL -1
int V, E;

vector<int> G[MAX_V];
int indegree[MAX_V];  // 入次数
vector<int> sorted;
// 参考
// https://qiita.com/Morifolium/items/6c8f0a188af2f9620db2
// https://hcpc-hokudai.github.io/archive/graph_topological_sort_001.pdf
// https://hcpc-hokudai.github.io/archive/graph_topological_sort_001.pdf

// 入次数が0の辺を探し, queueに入れる
// queueが空になるまで, 入次数を減らす
vector<int> TopologicalSortKahn() {
  queue<int> que;
  for (int v = 0; v < V; v++) {
    if (indegree[v] == 0) que.push(v);
  }
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (auto &v : G[u]) {
      indegree[v]--;
      if (indegree[v] == 0) que.push(v);
    }
    sorted.push_back(u);
  }
  return sorted;
}
// DFS 帰りがけ順 リバース
bool visited[MAX_V];

void DFS(int u) {
  visited[u] = true;
  for (auto &v : G[u]) {
    if (!visited[v]) DFS(v);
  }
  sorted.push_back(u);
}

// 複数回答OK
vector<int> TopologicalSortTarjan() {
  fill(visited, visited + MAX_V, false);
  for (int u = 0; u < V; u++) {
    if (!visited[u]) DFS(u);
  }
  reverse(sorted.begin(), sorted.end());
  return sorted;
}

int main() {
  cin >> V >> E;
  fill(indegree, indegree + MAX_V, 0);
  for (int i = 0; i < E; i++) {
    int s, t;
    cin >> s >> t;
    G[s].push_back(t);
    indegree[t]++;
  }
  // vector<int> res = TopologicalSortKahn();
  vector<int> res = TopologicalSortTarjan();
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << endl;
  }
}