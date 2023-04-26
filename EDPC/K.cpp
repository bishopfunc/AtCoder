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

bool dp[100010] = {false};

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> a(N);
  rep(i, 0, N) cin >> a[i];

  // dp[0] 石が0個は負け f負け、t勝ち
  rep(i, 0, K + 1) //石の数分シミュレートする, 残り0個から残りK個
    rep(j, 0, N) { //石の配列のindex
      if (i - a[j] >= 0) dp[i] |= !dp[i - a[j]]; // 負けなら勝ち //なぜ??|= F-T-Tになる
    }
  if (dp[K]) cout << "First" << endl; //初手が勝ちか負けか
  else  cout << "Second" << endl;
}