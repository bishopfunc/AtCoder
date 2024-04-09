#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
// UP, DOWN, LEFT, RIGHT
const vector<int> DX = {0, 0, -1, 1};
const vector<int> DY = {1, -1, 0, 0};

int main() {
  int N, M;
  cin >> N >> M;
  string S[N][M];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      char s;
      cin >> s;
      S[i][j] = s;
    }
  }
  // 2部グラフマッチング 市松模様に塗る
  // i + jが偶数 -> 黒, 奇数->白
  mf_graph<int> g(N * M + 2);
  int s = N * M, t = s + 1;
  // s->i cap=1
  // i->N*M+j cap=1
  // N*M+j->t cap=1
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      // 偶数 黒のみ探索するから重複しない
      if ((i + j) % 2 == 0) {
        for (int dir = 0; dir < 4; dir++) {
          int i2 = i + DX[dir], j2 = j + DY[dir];
          if (i2 < 0 || i2 >= N || j2 < 0 || j2 >= M) continue;
          if (S[i][j] == "." && S[i2][j2] == ".")
            g.add_edge(i * M + j, i2 * M + j2, 1);
          // 1行M個ある j*M
        }
      }
      // s->黒
      if ((i + j) % 2 == 0 && S[i][j] == ".") g.add_edge(s, i * M + j, 1);
      // 白->t
      if ((i + j) % 2 == 1 && S[i][j] == ".") g.add_edge(i * M + j, t, 1);
    }
  }
  int max_flow = g.flow(s, t);
  cout << max_flow << endl;
  for (auto &e : g.edges()) {
    // cell1とcell2に置くことを考える
    // 1行Mなので iは/M jは%M
    if (e.from == s || e.to == t || e.flow == 0) continue;
    int cell1_i = e.from / M, cell1_j = e.from % M;
    int cell2_i = e.to / M, cell2_j = e.to % M;
    // 同じ行 横に置く
    if (cell1_i == cell2_i) {
      if (cell1_j > cell2_j) swap(cell1_j, cell2_j);
      S[cell1_i][cell1_j] = ">";
      S[cell2_i][cell2_j] = "<";
    }
    // 同じ列 縦に置く
    else {
      if (cell1_i > cell2_i) swap(cell1_i, cell2_i);
      S[cell1_i][cell1_j] = "v";
      S[cell2_i][cell2_j] = "^";
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cout << S[i][j];
    }
    cout << endl;
  }
  cout << endl;
}