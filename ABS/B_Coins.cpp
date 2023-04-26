#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
int main() {
  int A, B, C, X;
  cin >> A >> B >> C >> X;
  int count = 0;
  rep(i, 0, A + 1) {
    rep(j, 0, B + 1) {
      rep(k, 0, C + 1) {
        if (i * 500 + j * 100 + k * 50 == X) count++;
      }
    }
  }
  cout << count << endl;
}