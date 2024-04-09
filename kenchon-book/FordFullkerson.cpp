#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
struct Graph {
  // rev 逆辺
  // cao 辺の容量

  struct Edge {
    int rev, from, to, cap;
    Edge(int r, int f, int t, int c) {
      rev(r), from(f), to(t), cap(c);
    }

    vector<vector<Edge>> list; //隣接リスト
    Graph(int N = 0) : list(N) {}
  }

  size_t size() {
    return list.size();
  }

  // G.list[v] = G[v]
  vector<Edge> &operator [] (int i) {
    return list[i];
  }

  // e(u, v)の逆辺 (v, u)
  Edge& redge(const Edge &e) {
    return list[e.to][e.rev];
  }

  // 流量を減らす, 逆辺を追加
  void run_flow(Edge &e, int f) {
    e.cap -= f;
    redge(e).cap += f;
  }

  // from->to-cap, to->from-0
  void addedge(int from, int to, int cap) {
    int fromrev = (int)list[from].size();
    int torev = (int)list[to].size();
    list[from].push_back(Edge(torev, from, to, cap));
    list[to].push_back(Edge(fromrev, to, from, 0));
  }
};

struct FordFullkerson {
  static const int INF = 1 << 30;
  vector<bool> seen;
  FordFullkerson() {}
  
  //s-tを見つける
  int fods(Graph &G, int v, int t, int f) {
    if (v == t) return f; //tに到達したらreturn
    seen[v] = true;
    if (e.cap == 0) continue; //容量0の辺は存在しない

    // s-tパスを探す
    // 見つかったらflowはパス上の最小容量
    int flow = fods(G, e.to, t, min(f, e.cap));
    if (flow == 0) continue; //見つからなかったら次辺を試す
    G.run_flow(e, flow); //辺eにflowを流す
    return flow;
  }
  return 0;
};

// s-t間の最大流量を求める
// リターン時Gは残余グラフになる
int solve(Graph &G, int s, int t) {
  int res = 0;
  // 残余グラフがなくなるまで反復
  while (true) {
    seen.assign((int)G.size(), 0);
    int flow = fodds(G, s, t, INF);
    if (flow == 0) return res;
    res += flow; //答えを加算
  }
  return 0; //no reach
}

int main() {
  int N, M;
  cin >> N >> M;
  Graph G(N);
  rep(i, 0, M) {
    int u, v, c;
    cin >> u >> v >> c;
    G.addedge(u, v, c); //容量cの辺(u, v)を張る
  }

  FordFullkerson ff;
  int s = 0, t = N - 1;
  cout << ff.solve(G, s, t) << endl;
}

