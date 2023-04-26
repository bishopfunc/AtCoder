#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define rep2(i, s, n) for (int i = (s); i >= (int)(n); i--) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));

//---------------------------------------------------------------------------------------------------
typedef long long ll;
int main() {
  int N; cin >> N;
  vector<ll> A(N), B(N);
  rep(i, 0, N) cin >> A[i] >> B[i];
  ll d, sum = 0;
  rep2(i, N - 1, 0) {
    A[i] += sum; //前回分の累計,初回は0
    ll r = A[i] % B[i];
    if (r == 0) d = 0;
    else d = B[i] - r;
    sum += d;
  }
  cout << sum << endl;
}