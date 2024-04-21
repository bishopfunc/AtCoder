#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// bit全探索 で行を選ぶ row
// 行の中で1列に同じ数字しかない列を選んでvecにする col
// vecの最大値をmapでカウント
// row * col

int main() {
  int H, W;
  cin >> H >> W;
  int P[H][W];
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) cin >> P[i][j];
  }
  int ans = -1;
  for (int bit = 0; bit < (1 << H); bit++) {
    vector<int> vec;
    int p = -1;
    for (int j = 0; j < W; j++) {
      map<int, int> m;
      for (int i = 0; i < H; i++) {
        // 数字の種類を記録
        if (bit & (1 << i)) { m[P[i][j]]++; }
        // 1種類の数字しかない
      }
      if (m.size() == 1) vec.push_back(m.begin()->first);
    }
    // vecの中で一番出現回数が多い
    map<int, int> m2;
    for (auto &v : vec) { m2[v]++; }
    int row_num, col_num = 0;
    // 行の数はmapの最大val
    for (auto &mv : m2) { col_num = max(mv.second, col_num); }
    // 列の数はbitで変換
    row_num = __builtin_popcount(bit);
    ans = max(ans, row_num * col_num);
  }
  cout << ans << endl;
}