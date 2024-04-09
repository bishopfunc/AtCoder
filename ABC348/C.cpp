#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  map<int, int> CtoA;
  for (int i = 0; i < N; i++) {
    int A, C;
    cin >> A >> C;
    if (CtoA.find(C) == CtoA.end()) {
      CtoA[C] = A;
    } else {
      CtoA[C] = min(CtoA[C], A);
    }
  }
  int maxD = 0;
  for (auto &[color, deliciousness] : CtoA) {
    maxD = max(maxD, deliciousness);
  }

  cout << maxD << endl;
}