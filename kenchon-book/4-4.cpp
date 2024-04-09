#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
int gcd(int m, int n) {
  int r = m % n;
  if (r == 0) return n;
  return gcd(n, r);
}

int main() {
  int M, N;
  cin >> M >> N;
  cout << gcd(M, N) << endl;
}

