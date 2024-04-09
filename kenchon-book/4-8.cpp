#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
typedef long long ll;
vector<ll> memo;

ll fib (int n){

  if (n == 0) return 0;
  else if (n == 1) return 1;
  if (memo[n] != -1) return memo[n];

  return memo[n] = fib(n - 1) + fib(n - 2);
}

int main () {
  int N; cin >> N;
  memo.assign(N, -1);
  fib(N - 2);
  ll res = 0;
  rep(i, 2, N - 1) res += memo[i];
  cout << res << endl;
}