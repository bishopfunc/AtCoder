#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll S[1002][1002];

// 累積和は 0~ 計算
// 入力が 0-1000 -> 1-1001に変更してあげる

int main() {
  int N;
  cin >> N;

  for (int i = 1; i <= 1000; i++) {
    for (int j = 1; j <= 1000; j++) { S[i][j] = 0LL; }
  }
  for (int i = 0; i < N; i++) {
    int lx, ly, rx, ry;
    cin >> lx >> ly >> rx >> ry;
    // 左下 lx,ly 右上 rx,ry
    // 進む方向の最初が+
    // 止まる点の後が-
    lx++;
    ly++;
    rx++;
    ry++;
    S[lx][ly]++;
    S[rx][ry]++;
    S[rx][ly]--;
    S[lx][ry]--;
    // 0,0 1,1で考えたとき 1x1の領域は0,0を含み, 1,1は+1,+1
  }
  // yoko
  for (int i = 1; i <= 1001; i++) {
    for (int j = 1; j <= 1001; j++) { S[i][j] += S[i][j - 1]; }
  }
  // tate
  for (int j = 1; j <= 1001; j++) {
    for (int i = 1; i <= 1001; i++) { S[i][j] += S[i - 1][j]; }
  }

  vector<ll> k(N + 1, 0);
  for (int i = 1; i <= 1001; i++) {
    for (int j = 1; j <= 1001; j++) {
      ll num = S[i][j];
      k[num]++;
    }
  }
  for (int i = 1; i <= N; i++) cout << k[i] << endl;
}