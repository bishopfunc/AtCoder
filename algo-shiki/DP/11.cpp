// なんでDP遷移式が成立するのかよくわからない, 問題設定もあまりよくわかってない
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
int dp[110] = {0}; //時刻[t-1,t]でオフにしたときの最大ｇ, 

int main() {
  int T; cin >> T;
  int g[T][T]; 
  rep(i, 0, T) rep(j, 0, T) cin >> g[i][j];
  rep(t, 1, T + 2) //[1, T+1]に直す, tについてシミュレーションする //for(t; t<=N+1; t++)
    rep(i, 0, t)
      rep(j, i + 1, t) // [i, j(i+1)]をかんがえる
        chmax(dp[t], dp[i] + g[i][j - 1]); //jが増える前???
        
  cout << dp[T + 1] << endl;
}