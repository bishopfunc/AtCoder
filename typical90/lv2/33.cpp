#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// コーナケースの問題

int main() {
  int H, W;
  cin >> H >> W;
  // 奇数なら+1
  // 左上に配置したとき最も多い
  // 2x2が何個作れるか

  // 2x2の領域以下なら不適切じゃない!マジかよ
  if (H == 1 || W == 1) {
    cout << H * W << endl;
    return 0;
  }

  if (H % 2 == 1) H++;
  if (W % 2 == 1) W++;
  cout << H * W / 4 << endl;

  // (3+1)/2=2 (4+1)/2=2
  // cout << ((H + 1) / 2) * ((W + 1) / 2) << endl;  // でも可
}