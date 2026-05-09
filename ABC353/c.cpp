#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod (ll)1e8

ll f(ll x, ll y) { return (x + y) % mod; }

int main() {
  int N;
  cin >> N;
  ll A[N + 1], S[N + 1];
  ll ans = 0;
  A[0] = 0;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
    S[i] = S[i - 1] + A[i];
  }
  for (int i = 1; i <= N - 1; i++) {
    ll t = (A[i] * (N - i)) + (S[N] - S[i]);
    if (t >= mod) {
      for (int j = i + 1; j < N; i++) { 
        t += ((A[i] + A[j]) % mod);
      }
    }
    // cout << "t1: " << (A[i] * (N - i)) << ", t2: " << (S[N] - S[i]) << endl;
    // cout << t << endl;
    // cout << t % mod << endl;

    if (N - i == 1) ans += (t %= mod);
  }
  cout << ans << endl;
}