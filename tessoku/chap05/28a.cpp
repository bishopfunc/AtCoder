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
int mod = 10000;


int main() {
  int N; char T; int A; int res = 0;
  cin >> N;
  rep(i, 0, N) {
    cin >> T >> A;
    if (T == '+') res += A;
    else if (T == '-') res -= A;
    else if (T == '*') res *= A;
    if (res < 0) res += mod;
    res %= mod;
    cout << res << endl;
  }
}