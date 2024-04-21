#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// マンハッタン距離なので、最短のXとYは別
// ある点を右に動かすと 1~N 左の点の数*(+1) + 右の点の数*(-1)

int main() {
  int N;
  cin >> N;
  vector<ll> X(N), Y(N);
  for (int i = 0; i < N; i++) { cin >> X[i] >> Y[i]; }
  // nth_element ソートせずに中央値を見つける
  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());
  int x = X[N / 2];
  int y = Y[N / 2];
  ll sum = 0;

  for (int i = 0; i < N; i++) {
    sum += abs(x - X[i]);
    sum += abs(y - Y[i]);
  }
  cout << sum << endl;
}