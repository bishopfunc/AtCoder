#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const ll INF = 1LL << 60;
//---------------------------------------------------------------------------------------------------
int dp[3010][3010]; //dpの意味, i,j番目までのLCSの長さ

int main() {
  string s, t;
  cin >> s >> t;
  
  dp[0][0] = 0;
  rep(i, 0, (int)s.size()) 
    rep(j, 0, (int)t.size()) {
      // 1文字伸びる
      if (s[i] == t[j]) chmax(dp[i + 1][j + 1], dp[i][j] + 1);
      // 伸びない
      chmax(dp[i + 1][j + 1], dp[i][j + 1]);
      chmax(dp[i + 1][j + 1], dp[i + 1][j]);
  }

  int i = (int)s.size();
  int j = (int)t.size();
  string res = "";
  while (i > 0 && j > 0) {
    if (dp[i][j] == dp[i - 1][j]) i--; // (i-1,j) => (i,j)
    else if (dp[i][j] == dp[i][j - 1]) j--; // (i,j-1) => (i,j)
    else {
      res = s[i - 1] + res;  // (i-1,j-1) => (i,j) 
      i--; j--;
    }
  }
  cout << res << endl;
}