#include <bits/stdc++.h>

#include <regex>
using namespace std;
typedef long long ll;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> G[N + 1];
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  int ans = 0;
  for (int u = 1; u <= N; u++) {
    int cnt = 0;
    for (auto &v : G[u]) {
      if (v < u) cnt++;
    }
    if (cnt == 1) ans++;
  }
  cout << ans << endl;
}