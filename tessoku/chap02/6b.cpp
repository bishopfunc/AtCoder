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
  int N; cin >> N;
  vector<int> A(N + 1), S(N + 1);
  rep(i, 1, N + 1) cin >> A[i];
  S[0] = 0;
  rep(i, 1, N + 1) S[i] = S[i - 1] + A[i];
  int Q; cin >> Q;
  rep(i, 0, Q) {
    int l, r;
    cin >> l >> r;
    int atari = S[r] - S[l - 1];
    int hazure = r - l + 1 - atari;
    if (atari > hazure) cout << "win" << endl;
    else if (atari < hazure) cout << "lose" << endl;
    else if (atari == hazure) cout << "draw" << endl;
  }
}