#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N, Q;
  cin >> N >> Q;
  bitset<1001> bit;
  for (int i = 1; i <= N; i++) { bit.set(i); }

  for (int i = 0; i < Q; i++) {
    int T;
    cin >> T;
    bit.flip(T);
  }
  cout << bit.count() << endl;
}