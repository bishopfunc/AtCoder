#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------

int main() {
  int H, W; cin >> H >> W;
  vector<string> maze(H);
  rep(i, 0, H) cin >> maze[i];

  rep(i, 0, H) rep(j, 0, W) {
    int c = 0;
    if (maze[i][j] == '.') {
      // '.'を中心に観察する
      rep(di, -1, 2) rep(dj, -1, 2) {
        if (di == 0 && dj == 0) continue; // (0,0)ならスキップ
        int n_i = i + di;
        int n_j = j + dj;
        if ((n_i < H && n_j < W && n_i >= 0 && n_j >= 0) && (maze[n_i][n_j] == '#')) c++;
        // 範囲内 AND '#'である
      }
      maze[i][j] = char(c + '0'); // '.'なら数字を埋める
    }
  }

  rep(i, 0, H) cout << maze[i] << endl;
}