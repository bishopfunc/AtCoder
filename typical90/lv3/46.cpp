#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  vector<ll> A(N), B(N), C(N);
  vector<ll> num_A(46, 0), num_B(46, 0), num_C(46, 0); // 余りで分類
  // (A % 46 + B % 46 + C % 46) %46 = (A + B + C) % 46
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) cin >> B[i];
  for (int i = 0; i < N; i++) cin >> C[i];
  for (int i = 0; i < N; i++) {
    num_A[A[i] % 46]++;
    num_B[B[i] % 46]++;
    num_C[C[i] % 46]++;
  }
  ll res = 0;
  for (int i = 0; i < 46; i++) {
    for (int j = 0; j < 46; j++) {
      for (int k = 0; k < 46; k++) {
        // i j k が分かれば、その組み合わせa*b*cを計算
        if ((i + j + k) % 46 == 0) res += (num_A[i] * num_B[j] * num_C[k]);
      }
    }
  }
  cout << res << endl;
}