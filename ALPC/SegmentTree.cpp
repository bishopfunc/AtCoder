#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

ll op(ll a, ll b) { return max(a, b); }

ll e() { return (ll)(-1); }
int tmp_V;
// v<= Ajを満たす最小のj
// x < Vの二分探索
bool f(ll x) { return x < tmp_V; };

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<ll> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  segtree<ll, op, e> sg(A);
  for (int i = 0; i < Q; i++) {
    int T, X, V, L, R;
    cin >> T;
    if (T == 1) {
      cin >> X >> V;
      sg.set(X - 1, V);
    } else if (T == 2) {
      cin >> L >> R;
      cout << sg.prod(L - 1, R) << endl;
      // input(1, N) prod(l, r)->op(a[l], ..., a[r - 1])
      // prodには実際の区間の1つ右を渡す
      // opが実行, 最大値なのでmax
    } else if (T == 3) {
      cin >> X >> tmp_V;
      cout << sg.max_right<f>(X - 1) + 1 << endl;
      // max_right(int l)
      // min_left 木の左
      // max_right 木の右
      // 今回はMAXだから大きいのが上(左)
      // 最大値の最小値は右
      // max_rightないときr=N N+1で良い
    }
  }
}