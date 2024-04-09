#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  bool ans = false;
  // K <2 N - 2 はそもそも辿り着けない
  // 5x5なら8stepでつける, 9は超えてしまう
  if (K >= N * 2 - 2 && K % 2 == 0) ans = true;
  cout << (ans ? "Yes" : "No") << endl;
}