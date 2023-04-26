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
  int N; cin >> N;
  bool resFlag = false;
  vector<int> A(N);
  rep(i, 0, N) cin >> A[i];
  sort(all(A));
  rep(i, 0, N) rep(j, 0, N) rep(k, 0, N) {
    if (i == j || j == k || i == k) continue;
    if (A[i] + A[j] + A[k] == 1000) resFlag = true;
  }
  if(resFlag) cout << "Yes" << endl;
  else cout << "No" << endl;
}