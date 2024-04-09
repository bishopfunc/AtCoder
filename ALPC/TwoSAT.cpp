#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

// https://qiita.com/sysdev/items/c6b707666541bacd22bf
int main() {
  int N, D;
  cin >> N >> D;
  vector<int> X(N), Y(N);
  for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];

  two_sat ts(N);
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (abs(X[i] - X[j]) < D) ts.add_clause(i, false, j, false);
      if (abs(X[i] - Y[j]) < D) ts.add_clause(i, false, j, true);
      if (abs(Y[i] - X[j]) < D) ts.add_clause(i, true, j, false);
      if (abs(Y[i] - Y[j]) < D) ts.add_clause(i, true, j, true);
    }
  }
  // else ifでなくif 複数の選び方がある
  // ijの組み合わせXX XY YX YYがある
  // X_i - X_j < D => !(X_i && X_j) => !X_i || !X_j
  // 上のORで繋げた部分のnotを入力してる
  // !X_i || X_j なら X_i->X_j !X_j->!X_i のグラフが作れる？
  // X_i || X_j は Fの時にどうなるかを考える F→T T→F
  // 効率的にトポロジカルソートし、同じ連結成分でTとFが同時に存在して矛盾
  if (!ts.satisfiable()) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  auto ans = ts.answer();
  for (int i = 0; i < N; i++) {
    if (ans[i]) cout << X[i] << endl;
    // true = xiを選ぶことなので
    else
      cout << Y[i] << endl;
  }
}