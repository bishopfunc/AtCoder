#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod (ll)(1e9 + 7)
typedef long long ll;

// N=2で考えてみよう
// 合計だからsum*sum*sumの因数分解にできるぜ

int main() {
  int N;
  cin >> N;
  int A[N][6];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 6; j++) { cin >> A[i][j]; }
  }
  ll res = 1;
  for (int i = 0; i < N; i++) {
    ll sum = 0;
    sum =
        (sum + A[i][0] + A[i][1] + A[i][2] + A[i][3] + A[i][4] + A[i][5]) % mod;
    res = (res * sum) % mod;
  }

  cout << res << endl;
}