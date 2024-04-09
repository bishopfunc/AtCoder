#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100001
int num[MAX_N];   // ボールの個数
bool red[MAX_N];  // 赤が存在する可能性がある

int main() {
  int N, M;
  cin >> N >> M;
  fill(num, num + MAX_N, 1);  // 1個ボール
  fill(red, red + MAX_N, false);
  red[1] = true;  // 1番目は赤
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    num[x]--;
    num[y]++;
    if (red[x]) red[y] = true;
    if (num[x] == 0) red[x] = false;
    // 0なら可能性なし、それ以外は僅かに可能性ある
    //  コップに赤い水を移す
  }
  int cnt = 0;
  for (int i = 1; i <= N; i++)
    if (red[i]) cnt++;
  cout << cnt << endl;
}