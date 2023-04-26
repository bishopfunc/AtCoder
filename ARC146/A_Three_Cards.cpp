#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
int main() {
  int N; cin >> N;
  vector<int> A(N);
  vector<int> B(N);
  rep(i, 0, N) cin >> A[i];
  B = A;
   rep(i, 0, N) {
    A = B;
    A.erase(cbegin(A) + i);
    rep(j, 0, N - 1) {
      A.erase(cbegin(A) + j);
      rep(k, 0, N - 2) {
        
      }
    }
  }
}