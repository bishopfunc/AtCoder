#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    ll N, M, A, B;
    cin >> N >> M >> A >> B;
    cout << floor_sum(N, M, A, B) << endl;
  }
}