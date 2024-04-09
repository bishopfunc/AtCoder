#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define INF (ll)1e9
#define MAX_A (ll)1e9

// 最小費用流問題
int main() {
  ll N, K;
  cin >> N >> K;
  mcf_graph<ll, ll> g(2 * N + 2);
  int s = 2 * N, t = 2 * N + 1;  // s: 始点, t: 終点
  // s->t cap:inf cost:0 無限 選ぶ個数はK個以下なので、無限に流せる辺を用意
  // s->i cap:K cost:0 行の選び方はK通り
  // i->N+j cap:1 cost:-A[i][j] 行i列jの数字を選ぶと、A[i][j]のコストがかかる
  // N+j->t cap:K cost:0 列の選び方はK通り
  g.add_edge(s, t, N * K, MAX_A);
  // 実際はcap:INFでもいいが、K*N個選ぶので、K*N個以下にする
  // 実際はcost:0でもいいが、全部+MAX_Aしているので、MAX_Aにする
  for (int i = 0; i < N; i++) {
    g.add_edge(s, i, K, 0);
    g.add_edge(i + N, t, K, 0);
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      ll A;
      cin >> A;
      g.add_edge(i, j + N, 1, MAX_A - A);
      // マイナスをつけて最大->最小コストに変換
      // マイナスは受け付けない
    }
  }
  auto [max_flow, min_cost] = g.flow(s, t, K * N);
  // N行に対してK個以下選ぶので、N*K個選ぶ
  // 以下の部分はs->tに流れるのが最小になるので問題ない
  cout << -(min_cost - K * N * MAX_A) << endl;
  // K*N*MAX_A分最小コストが増える、最小->最大に変換

  string grid[N][N];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      grid[i][j] = ".";
    }
  }

  auto edges = g.edges();
  for (auto e : edges) {
    // s->t s->i N+j->tは無視
    if (e.from == s || e.to == t || e.flow == 0) continue;
    int i = e.from, j = e.to - N;  // 最初にj+Nしてる
    grid[i][j] = "X";
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << grid[i][j];
    }
    cout << endl;
  }
  cout << endl;
}