#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------

int main() {
  int N; cin >> N;
  vector <int> A(N);
  int count = 0;
  bool continue_flag = true;
  rep(i, 0, N) cin >> A[i];
  while (true) {
    rep(i, 0, N) {
      if (A[i] % 2 != 0) goto OUT;
      else A[i] /= 2;
    }
    count++;
  }
  OUT:
  cout << count << endl;
}