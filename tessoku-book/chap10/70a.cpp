#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
typedef long long ll;
typedef unsigned long long ull;

// 遷移をグラフとして考える
// 1ビット変える

// 4桁なら 0~15に対して 操作ABC後の数字とノードをつなげる
vector<ull> G[1024];  // 2^10
vector<ull> dist(1024, INF);

void bfs(ull s) {
  queue<ull> que;
  que.push(s);
  dist[s] = 0;
  while (!que.empty()) {
    ull u = que.front();
    que.pop();
    // cout << u << endl;
    for (auto &v : G[u]) {
      if (dist[v] != INF) continue;
      que.push(v);
      dist[v] = dist[u] + 1;
    }
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  int A[N];
  vector<bitset<10>> action(M);
  bitset<10> start;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    start.set(i, A[i]);
  }
  // cout << start << endl;
  for (int i = 0; i < M; i++) {
    int X, Y, Z;
    cin >> X >> Y >> Z;
    action[i].set(X - 1, 1);
    action[i].set(Y - 1, 1);
    action[i].set(Z - 1, 1);
    // XYZ 1-index l->r
    // bit 0-index l<-r
    // cout << action[i] << endl;
  }
  for (int bit = 0; bit < (1 << N); bit++) {
    for (int i = 0; i < M; i++) {
      bitset<10> _from(bit);
      bitset<10> _to = _from ^ action[i];
      ull from = _from.to_ullong();
      ull to = _to.to_ullong();
      G[from].push_back(to);
      G[to].push_back(from);
    }
  }
  bfs(start.to_ullong());  // 入力Aの二進数で探索
  int ans = dist[(1 << N) - 1];
  cout << (ans >= INF ? -1 : ans) << endl;  // 2^N-1 = 1111 がゴール
}
