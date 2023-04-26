// なんでDP遷移式が成立するのかよくわからない
#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const ll LINF = 1LL << 60;
const int INF = 1 << 29;
const ll MOD = 1000;
//---------------------------------------------------------------------------------------------------
int dp[110][110];

int main() {
  int N, M; cin >> N >> M;
  int c[N][M];
  rep(i, 0, N) rep(j, 0, M) cin >> c[i][j];
  rep(i, 0, N + 1) rep(j, 0, M + 1) dp[i][j] = INF;

  dp[0][0] = 0;
  rep(i, 0, N) 
    rep(j, 0, M) {
      chmin(dp[i + 1][j + 1], dp[i + 1][j] + c[i][j]);
      chmin(dp[i + 1][j + 1], dp[i][j + 1] + c[i][j]);
      chmin(dp[i + 1][j + 1], dp[i][j] + c[i][j]);
    }
  cout << dp[N][M] << endl;
}