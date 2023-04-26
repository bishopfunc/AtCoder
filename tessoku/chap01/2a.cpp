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
int main() {
  int N, X; cin >> N >> X;
  vector<int> A(N);
  rep(i, 0, N) cin >> A[i];
  bool resFlag = false;
  rep(i, 0, N) if (X == A[i]) resFlag = true;
  if(resFlag) cout << "Yes" << endl;
  else cout << "No" << endl;
}