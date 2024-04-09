#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main() {
  int N, M;
  cin >> N >> M;
  scc_graph g(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    g.add_edge(a, b);
  }
  auto scc = g.scc();
  cout << scc.size() << endl;
  for (auto &v_vec : scc) {
    cout << v_vec.size();
    for (auto &v : v_vec) {
      cout << " " << v;
    }
    cout << endl;
  }
}