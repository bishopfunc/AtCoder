#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const ll INF = 1LL << 60;
//---------------------------------------------------------------------------------------------------
ll w[110], v[110];
ll dp[110][100010] = {0}; //[N, W]

int main() {
  int N; ll W;
  cin >> N >> W;
  rep(i, 0, N) cin >> w[i] >> v[i];
  rep(i, 0, N) {
    rep(sum_w, 0, W + 1) {
      // 選ぶとき
      if (sum_w - w[i] >= 0) chmax(dp[i + 1][sum_w], dp[i][sum_w - w[i]] + v[i]);
      // 選ばないとき
      chmax(dp[i + 1][sum_w], dp[i][sum_w]);
    }
  }
  cout << dp[N][W] << endl;
}