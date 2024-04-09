#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, X;
  cin >> N >> X;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  sort(A.begin(), A.end());
  bool ans = binary_search(A.begin(), A.end(), X);
  cout << (ans ? "Yes" : "No") << endl;
}