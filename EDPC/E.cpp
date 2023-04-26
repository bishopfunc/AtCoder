#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const ll INF = 1LL << 60;
const int MAX_N = 110;
const int MAX_V = 100010; //なぜ？？10^3じゃないの？？？
//---------------------------------------------------------------------------------------------------
ll w[MAX_N], v[MAX_N];
ll dp[MAX_N][MAX_V];  //[N. V]

int main() {
  int N; ll W;
  cin >> N >> W;
  rep(i, 0, N) cin >> w[i] >> v[i];
  rep(i, 0, MAX_N) rep(v, 0, MAX_V) dp[i][v] = INF; //initialize
  dp[0][0] = 0;

  rep(i, 0, N) {
    rep(sum_v, 0, MAX_V) {
      // 選ぶとき
      if (sum_v - v[i] >= 0) chmin(dp[i + 1][sum_v], dp[i][sum_v - v[i]] + w[i]);
      // 選ばないとき
      chmin(dp[i + 1][sum_v], dp[i][sum_v]);
    }
  }
  ll max = 0;
  rep(sum_v, 0, MAX_V) if (dp[N][sum_v] <= W) max = sum_v;
  // knapsackの容量範囲内なら
  cout << max << endl;
}