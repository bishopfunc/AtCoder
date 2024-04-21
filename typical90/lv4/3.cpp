#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF -1

vector<vector<int>> G;
vector<int> dist;

void dfs(int s) {
  fill(dist.begin(), dist.end(), INF);
  queue<int> Q;
  Q.push(s);
  dist[s] = 0;
  while (!Q.empty()) {
    int v = Q.front();
    // cout << "v: " << v << ", dist[v]: " << dist[v] << endl;
    Q.pop();
    for (auto &u : G[v]) {
      if (dist[u] != INF) continue;
      Q.push(u);
      dist[u] = dist[v] + 1;
    }
  }
}

int main() {
  int N;
  cin >> N;
  G.resize(N);
  dist.resize(N);
  for (int i = 1; i <= N - 1; i++) {
    int A, B;
    cin >> A >> B;
    A--;
    B--;
    G[A].push_back(B);
    G[B].push_back(A);
  }
  dfs(0);
  // cout << *max_element(dist.begin(), dist.end()) << endl;
  int max_1_id = distance(dist.begin(), max_element(dist.begin(), dist.end()));
  dfs(max_1_id);
  int max_2 = *max_element(dist.begin(), dist.end());
  cout << max_2 + 1 << endl;
}