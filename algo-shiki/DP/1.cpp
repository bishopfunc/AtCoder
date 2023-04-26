#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
//---------------------------------------------------------------------------------------------------

int dp[10010];

int main() {
  int N; cin >> N;
  vector<int> a(N);
  rep(i, 0, N) cin >> a[i];
  
  dp[0] = 0;  //ini
  rep(i, 0, N)dp[i + 1] = max(dp[i] + a[i], dp[i]); //選ぶ場合, 選ばない場合
  // a[i]を選ぶかだけ考える, a[i-1],a[i-2]...はすでに知ってる
  cout << dp[N] << endl;

}