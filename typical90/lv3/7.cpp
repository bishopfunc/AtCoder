#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N, Q;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  sort(A.begin(), A.end());
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int B;
    cin >> B;
    int id = lower_bound(A.begin(), A.end(), B) - A.begin();
    // keyより大きい最小の
    // id - 1が差が小さい可能性あり
    // id - 1配列外参照に注意
    if (id >= 1) cout << min(abs(A[id] - B), abs(A[id - 1] - B)) << endl;
    else cout << abs(A[id] - B) << endl;
  }
}