#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
int main() {
  int N; cin >> N;
  vector<int> a(N);
  rep(i, 0, N) cin >> a[i];
  
  vector<int> s(N + 1, 0); //s[0] = 0;
  rep(i, 0, N) s[i + 1] = s[i] + a[i];
}