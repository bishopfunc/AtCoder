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

int dp[110][1010];

int main() {
  int N, W; 
  cin >> N >> W;
  vector<int> value(N);
  vector<int> weight(N);
  rep(i, 0, N) cin >> weight[i] >> value[i];
  
  rep(w, 0, W) dp[0][w] = 0; //ini
  rep(i, 0, N) 
    rep(w, 0, W + 1) {
      if (w - weight[i] >= 0) chmax(dp[i + 1][w], dp[i][w - weight[i]] + value[i]);
      chmax(dp[i + 1][w], dp[i][w]);
    }
  // rep(i, 0, N) 
  //   rep(w, 0, W + 1) {
  //     if (w - weight[i] >= 0) dp[i + 1][w] = max(dp[i][w], dp[i][w - weight[i]] + value[i]); // 
  //     else dp[i + 1][w] = dp[i][w]; 
  //   }
    // chmax のときはelseなし, maxのときはelseあり？
  cout << dp[N][W] << endl;
}