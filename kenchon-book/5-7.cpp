#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));

//---------------------------------------------------------------------------------------------------
typedef long long ll;

template<class T> void chmax(T &a, T b) {
  if (a < b) a = b;
}

int main() {
  int N; ll W; 
  cin >> N >> W;
  vector<ll> weight(N), value(N);
  vector<vector<ll>>dp(N + 1, vector<ll>(W + 1, 0));
  rep(i, 0, N) cin >> weight[i] >> value[i];
  rep(i, 0, N) {
    rep(w, 0, W + 1) {
      // W自身も含む
      // i番目を選ぶ場合
      if (w > weight[i]) chmax(dp[i + 1][w], dp[i][w - weight[i]] + value[i]); //valをつけて更新
      
      // i番目を選ばない場合
      chmax(dp[i + 1][w], dp[i][w]); //上が実行したあと上書きしても良い
    } 
  }
  cout << dp[N][W] << endl;

// 表示
  cout << "" << "i/w";
  cout.width(2);
  rep(w, 0, W + 1) {
    cout << w <<  " "; 
    cout.width(2);
  }
  cout << endl;
  rep(i, 0, N + 1) {
    cout << i <<  " "; cout.width(2);
    rep(j, 0, W + 1) {
      cout << dp[i][j] <<  " "; cout.width(2);
    } 
    cout << endl; 
  } 
}