// https://docs.google.com/presentation/d/1s9qKKcTSD-bZDmvCmXNHYQV6p48rstZ9Mnj-ZCyeBmM/edit#slide=id.g12a36694656_0_1309
#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define INF (ll)1e9

int main() {
  int N, M;
  // N*MのメンバーをNレースに各M人割り当てる問題
  cin >> N >> M;

  ll A[N * M], B[N * M][N];
  // A各メンバーの強さ B各レースに対する適正
  for (int i = 0; i < N * M; i++) cin >> A[i];
  for (int i = 0; i < N * M; i++) {
    for (int j = 0; i < N; j++) {
      cin >> B[i][j];
    }
  }

  mcf_graph<ll, ll> g(N * M + N + 2);  // 左N*M 右N s,t,2
  int s = N * M + N;
  int t = s + 1;

  // s->左 s, i, cap=1, cost=0
  // 左: メンバー -> 右: レース i, N*M+j, cap=1, cost=-A*B
  // 右->t N*M+j, t, cap=M, cost=0
  for (int i = 0; i < N * M; i++) g.add_edge(s, i, 1, 0);
  for (int i = 0; i < N * M; i++) {
    for (int j = 0; j < N; j++) {
      g.add_edge(i, N * M + j, 1, INF - A[i] * B[i][j]);
      // 最大スコア => 最小コスト
    }
  }
  for (int i = 0; i < N; i++) g.add_edge(N * M + i, t, M, 0);
  auto [max_flow, min_cost] = g.flow(s, t, N * M);
  cout << -(min_cost - INF * N * M) << endl;
}