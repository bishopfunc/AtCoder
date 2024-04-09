// bit全探索
// https://drken1215.hatenablog.com/entry/2019/12/14/171657

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  // for (int i = 0; i < N; ++i) cin >> A[i];
  int cnt = 0;
  for (int bit = 0; bit < (1 << N); bit++) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
      int mask = 1 << i;
      // if (bit & mask) sum += A[i];
    }

    cout << "bit: " << bitset<8>(bit).to_string() << ", sum: " << sum << endl;
    if (K == sum) cnt++;
  }
  cout << cnt << endl;
}