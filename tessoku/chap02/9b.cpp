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
int X[1510][1510] = {};
int S[1510][1510] = {};

int main() {
  int N;
  cin >> N;
  int a, b, c, d;
  rep(i, 0, N) {
    cin >> a >> b >> c >> d;
    X[a][b] += 1;
    X[c + 1][d + 1] += 1;
    X[a][d + 1] -= 1;
    X[c + 1][b] -= 1;
  }
  // 横の累積和
  rep(i, 1, 1510) rep(j, 1, 1510) {
    S[i][j] = S[i][j - 1] + X[i][j];
  }
  // 縦の累積和
  rep(i, 1, 1510) rep(j, 1, 1510) {
    S[i][j] = S[i - 1][j] + S[i][j];
  }    

  int res = 0;
  rep(i, 1, 1510) rep(j, 1, 1510) if (S[i][j] >= 1) res++;
  cout << res / N << endl; //? 7
}