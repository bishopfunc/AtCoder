#include <bits/stdc++.h>
#include <iomanip>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
//---------------------------------------------------------------------------------------------------
// DP[i][j] i:投げたコイン, j: 表になったコイン

double dp[3010][3010] = {0};


int main() {
  int N; cin >> N;
  vector<double> p(N);
  rep(i, 0, N) cin >> p[i];

  dp[0][0] = 1.0;
  rep(i, 0, N) 
    rep(j, 0, i + 1) {
      dp[i + 1][j + 1] += dp[i][j] * p[i];
      dp[i + 1][j] += dp[i][j] * (1.0 - p[i]);
    }
  double res = 0;
  rep(j, N / 2 + 1, N + 1) res += dp[N][j];
  // [N/2+1, N] 右下に集中する, なぜか
  cout << setprecision(10) << res << endl;
}