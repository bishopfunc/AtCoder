#include <bits/stdc++.h>
#include <unordered_set>

using namespace std; 
typedef long long ll;
#define rep(i, s, n) for (ll i = (s); i < (ll)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
int main() {
  ll N, Q;
  ll q, i, x;
  map<int, ll> M;
  cin >> N;
  vector<ll> A(N);
  ll base = 0;
  rep(i, 0, N) {
    cin >> A[i];
    M[i] = A[i];
  }
  cin >> Q;
  while (Q--) {
    cin >> q;
    // in_place
    if (q == 1) {
      cin >> x; 
      base = x;
      M.clear();
    }
    // add
    else if (q == 2) {
      cin >> i >> x;
      M[i - 1] += x;
    }
    // print
    else if (q == 3) {
      cin >> i;
      cout << M[i - 1] + base << endl;
    }
  }
}