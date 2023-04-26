#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
int main() {
  int N, Y; 
  cin >> N >> Y;
  rep(i, 0, N + 1) rep(j, 0, N + 1) {
    int k = N - i - j;
    if (k >= 0 && i * 10000 + j * 5000 + k * 1000 == Y) {
      cout << i << " " << j << " " << k << endl;
      return 0;
    }
  }
  cout << -1 << " " << -1 << " " << -1 << endl;
}