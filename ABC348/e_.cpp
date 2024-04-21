#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF 1e9
vector<int> G[100001];
int C[100001];


// 開始ノードから他のすべてのノードへの最短距離を計算する関数
vector<int> bfs(int start, int N) {
  vector<int> distance(N + 1, INF);
  queue<int> q;
  q.push(start);
  distance[start] = 0;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : G[v]) {
      if (distance[u] == INF) {
        distance[u] = distance[v] + 1;
        q.push(u);
      }
    }
  }
  return distance;
}

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N - 1; i++) {
    int A, B;
    cin >> A >> B;
    G[A].push_back(B);
    G[B].push_back(A);  // 無向グラフ
  }
  for (int i = 1; i <= N; i++) {
    cin >> C[i];
  }

  ll min_f = INF;
  for (int u = 1; u <= N; u++) {
    auto distances = bfs(u, N);
    ll f = 0;
    for (int v = 1; v <= N; v++) {
      f += (ll)C[v] * distances[v];
    }
    min_f = min(min_f, f);
  }
  cout << min_f << endl;
}
