#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
int main() {
  int N; cin >> N;
  int sumA = 0, sumB = 0;
  vector<int> A (N);
  rep(i, 0, N) cin >> A[i];
  sort(all(A));
  reverse(all(A));
  rep(i, 0, N) {
    if (i % 2 == 0) sumA += A[i];
    else sumB += A[i];
  }
  cout << sumA - sumB << endl;

}