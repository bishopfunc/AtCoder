#include <bits/stdc++.h>
using namespace std;
#define MAX_A 100000
typedef long long ll;
// https://terumiyake.hatenablog.com/entry/2020/05/19/234416

// バケツソート
int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> bucket(MAX_A + 1);
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    bucket[a] += b;
  }
  ll ans = 0, id = 0;
  for (ans = 0; ans < MAX_A; ans++) {
    id += bucket[ans];
    if (id >= K) break;
  }
  cout << ans << endl;
}