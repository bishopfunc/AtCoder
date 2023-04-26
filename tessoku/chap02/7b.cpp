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
  int T, N; cin >> T >> N;
  vector<int> time(T + 1, 0), S(T + 1);
  rep(i, 0, N) {
    int l, r;
    cin >> l >> r;
    time[l]++;
    time[r]--; //r日目まで出席, r+1日目に減る
  }
  S[0] = time[0]; //t=0
  rep(i, 0, T) S[i + 1] = S[i] + time[i + 1]; //t[0]は計算した
  rep(i, 0, T) cout << S[i] << endl;
}