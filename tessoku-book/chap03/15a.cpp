#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) { cin >> A[i]; }
  vector<int> T = A;
  sort(T.begin(), T.end());
  T.erase(unique(T.begin(), T.end()), T.end());
  for (int i = 0; i < N; i++) {
    int pos = lower_bound(T.begin(), T.end(), A[i]) - T.begin();
    B[i] = pos;
  }
  for (int i = 0; i < N; i++) {
    if (i) cout << " ";
    cout << B[i] + 1; // i-index
  }
  cout << endl;
}