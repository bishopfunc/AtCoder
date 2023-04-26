#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
int main() {
  int N, X;
  cin >> N >> X;
  vector<int> a(N+1);
  rep(i, 1, N+1) cin >> a.at(i);
   rep(i, 1, N+1) if(a.at(i) == X) cout << i << endl;
}