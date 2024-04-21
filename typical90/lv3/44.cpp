#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, Q;
// シフト後からシフト前の配列のindex
int get_shift_id(int id, int shift) {
  int shift_id = id - shift;
  if (shift_id < 0) shift_id += N;
  return shift_id;
}

int main() {
  cin >> N >> Q;
  vector<ll> A(N), B(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    B[i] = i;
  }
  int shift = 0;
  for (int i = 0; i < Q; i++) {
    int T, x, y;
    cin >> T >> x >> y;
    if (T == 1) {
      x--;
      y--;
      x = get_shift_id(x, shift);
      y = get_shift_id(y, shift);
      // シフト前の配列をswap
      swap(A[x], A[y]);
    } else if (T == 2) {
      shift++;
      shift %= N;
      // シフト回数を記録するだけ
      // Nになったらシフトしないと同じ
    } else if (T == 3) {
      x--;
      x = get_shift_id(x, shift);
      cout << A[x] << endl;
    };
    // for (int i = 0; i < N; i++) {
    //   if (i) cout << " ";
    //   int id = get_shift_id(i, shift);
    //   cout << A[id];
    // cout << id;
    // }
    // cout << endl;
  }
}