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
int XY[1510][1510] = {0};
int S[1510][1510] = {0};

int main() {
  int N, Q;
  int x, y;
  cin >> N;
  rep(i, 0, N) { cin >> x >> y; XY[x][y] = 1; }

  // 横の累積和
  rep(i, 1, 1510) rep(j, 1, 1510) {
    S[i][j] = S[i][j - 1] + XY[i][j];
  }
  // 縦の累積和
  rep(i, 1, 1510) rep(j, 1, 1510) {
    S[i][j] = S[i - 1][j] + S[i][j];
  }    

  cin >> Q;
  rep(i, 0, Q) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << S[c][d] - S[c][b - 1] - S[a - 1][d] + S[a - 1][b - 1] << endl;
    cout << S[c][d] << " " <<  S[c][b - 1] << " " << S[a - 1][d] << " " << S[a - 1][b - 1] << " " << endl;
  }
  // rep(i, 1, N + 1) {
  //   rep(j, 1, N + 1) cout << S[i][j] << " ";
  //   cout << endl;
  // }  
}