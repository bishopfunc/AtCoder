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
int main() {
  int N; cin >> N;
  vector<int> A(N + 1), L(N + 1), R(N + 1), P(N + 1), Q(N + 1);
  rep(i, 1, N + 1) cin >> A[i];
  int D; cin >> D;
  rep(i, 1, D + 1) cin >> L[i] >> R[i];
  P[1] = A[1];
  for(int i = 2; i <= N; i++) P[i] = max(P[i - 1], A[i]);
  Q[N] = A[N];
  for(int i = N - 1; i >= 1; i--) Q[i] = max(Q[i + 1], A[i]);
  rep(i, 1, D + 1) cout << max(P[L[i] - 1], Q[R[i] + 1]) << endl;

}