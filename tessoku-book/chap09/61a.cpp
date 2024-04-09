#include <bits/stdc++.h>
using namespace std;

vector<int> G[100000];

int main() {
  int N, M;
  cin >> N >> M;
  int a, b;
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  for (int i = 1; i <= N; i++) {
    cout << i << ": {";
    for (int j = 0; j < G[i].size(); j++) {
      if (j) cout << ", ";
      cout << G[i][j];
    }
    cout << "}" << endl;
  }
}