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
  int D, N; cin >> D >> N;
  vector<int> day(D + 1, 0), S(D + 1);
  rep(i, 1, N + 1) {
    int l, r;
    cin >> l >> r;
    day[l]++;
    day[r + 1]--; //r日目まで出席, r+1日目に減る
  }
  S[0] = 0;
  rep(i, 1, D + 1) S[i] = S[i - 1] + day[i];
  rep(i, 1, D + 1) cout << S[i] << endl;
}