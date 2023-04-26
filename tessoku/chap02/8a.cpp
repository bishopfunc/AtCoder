#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define rep2(i, s, n) for (int i = (s) - 1; i >= (int)(n); i--) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
//---------------------------------------------------------------------------------------------------
int X[1510][1510];
int S[1510][1510] = {};

int main() {
  int H, W, Q;
  cin >> H >> W;
  rep(i, 1, H + 1) rep(j, 1, W + 1) cin >> X[i][j];

  // 横の累積和
  rep(i, 1, H + 1) rep(j, 1, W + 1) {
    S[i][j] = S[i][j - 1] + X[i][j];
  }
  // 縦の累積和
  rep(i, 1, H + 1) rep(j, 1, W + 1) {
    S[i][j] = S[i - 1][j] + S[i][j];
  }    

  cin >> Q;
  rep(i, 0, Q) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << S[c][d] - S[c][b - 1] - S[a - 1][d] + S[a - 1][b - 1] << endl;
    // cout << S[c][d] << " " <<  S[c][b - 1] << " " << S[a - 1][d] << " " << S[a - 1][b - 1] << " " << endl;
  }
  // rep(i, 1, H + 1) {
  //   rep(j, 1, W + 1) cout << S[i][j] << " ";
  //   cout << endl;
  // }  
}