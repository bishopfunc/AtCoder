#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define rep2(i, s, n) for (int i = (s) - 1; i >= (int)(n); i--) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
//---------------------------------------------------------------------------------------------------
int main() {
  int N, K; cin >> N >> K;
  int res = 0;
  rep(i, 1, N + 1) 
    rep(j, 1, N + 1) {
      int k = K - i - j;
      if (1 <= k && k <= N) {
        res++;
        // cout << i << " " << j << " " << k << endl;
      }
    }
  cout << res << endl;
}