#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
typedef long long ll;
const ll INF = 1LL << 60;
int N;
vector<ll> h;
vector<ll> dp;

template<class T> void chmin(T &a, T b) {
  if (a > b) a = b;
}


ll req(int i) {
  ll res = INF;
  if (dp[i] < INF) return dp[i];
  if (i == 0) return 0;
  chmin(res, req(i - 1) +  abs(h[i] - h[i - 1]));
  if (i > 1)  chmin(res, req(i - 2) +  abs(h[i] - h[i - 2]));
  return dp[i] = res;
}

int main() {
  cin >> N;
  h.resize(N);
  dp.assign(N, INF);
  
  rep(i, 0, N) cin >> h[i];


  rep(i, 1, N) {
    chmin(dp[i], dp[i - 1] +  abs(h[i] - h[i - 1]));
    if (i > 1) chmin(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
  }


  // rep(i, 0, N) cout << dp[i] << endl;
  cout << req(N - 1) << endl;

}