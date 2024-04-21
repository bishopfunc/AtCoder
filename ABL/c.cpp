#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define MAX_N 100
#define INF (int)1e9
#define NIL -1

int main() {
  int N, M;
  cin >> N >> M;
  dsu d(N);
  for (int i = 0; i < M; i++) {
    int A, B;
    cin >> A >> B;
    A--;
    B--;
    d.merge(A, B);
  }
  int ans = d.groups().size() - 1;
  // 連結成分の個数 - 1 = 必要な道路の数
  cout << ans << endl;
}