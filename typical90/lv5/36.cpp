#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// X: x-y cos(pi/2) - sin(pi/2)
// Y: x+y sin(pi/2) + cos(pi/2)
// 反時計に45度回転 = チェビシェフ距離
// マンハッタン距離は x y 独立にできる
// max(|x - x'| + |y - y'|...)
// max(|X - X'|,...|Y - Y'|...)
// なんなら X_max, X_min, Y_max, Y_minだけで良い

// 参考
// https://perogram.hateblo.jp/entry/2020/10/05/151022
// https://kagamiz.hatenablog.com/entry/2014/12/21/213931
// https://scrapbox.io/magurofly/%E3%83%9E%E3%83%B3%E3%83%8F%E3%83%83%E3%82%BF%E3%83%B3%E8%B7%9D%E9%9B%A2%E3%81%A845%E5%BA%A6%E5%9B%9E%E8%BB%A2

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<ll> X(N), Y(N);
  for (int i = 0; i < N; i++) {
    ll x, y;
    cin >> x >> y;
    X[i] = x - y;
    Y[i] = x + y;
  }
  ll min_X = *min_element(X.begin(), X.end());
  ll max_X = *max_element(X.begin(), X.end());
  ll min_Y = *min_element(Y.begin(), Y.end());
  ll max_Y = *max_element(Y.begin(), Y.end());
  for (int i = 0; i < Q; i++) {
    int q;
    cin >> q;
    q--;
    cout << max({abs(min_X - X[q]), abs(max_X - X[q]), abs(min_Y - Y[q]),
                 abs(max_Y - Y[q])})
         << endl;
  }
}