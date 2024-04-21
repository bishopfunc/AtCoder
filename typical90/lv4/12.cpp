#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;

// 赤及びその4マスは連結成分
// x,yはあるけどどうmergeする? x*N+y
int H, W;
int idx_sub(int x, int y, int h, int w) {
  if (x < 0 || x > h - 1 || y < 0 || y > w - 1) return -1;
  return x * w + y;
}
int idx(int x, int y) { return idx_sub(x, y, H, W); }
const vector<int> dx = {0, 0, -1, 1};
const vector<int> dy = {1, -1, 0, 0};

int main() {
  cin >> H >> W;
  bool red[H][W];
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) { red[i][j] = false; }
  }

  dsu d(H * W);
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int q;
    cin >> q;
    if (q == 1) {
      int r, c;
      cin >> r >> c;
      r--;
      c--;
      // 赤いマスなら塗らない
      // if (red[r][c]) continue;
      // 白いマスを赤く塗る
      red[r][c] = true;
      for (int j = 0; j < 4; j++) {
        int sx = r + dx[j], sy = c + dy[j];
        // 赤いマスの赤いマス上下左右を連結する 白いマスは移動できない
        // 赤いマスかつ正しいindex
        if (idx(sx, sy) != -1 && red[sx][sy]) {
          d.merge(idx(r, c), idx(sx, sy));
        }
        // cout << "nx: " << nx << ", ny: " << ny << endl;
        // cout << "idx(nx, ny): " << idx(nx, ny) << endl;
      }

    } else if (q == 2) {
      int ra, ca, rb, cb;
      cin >> ra >> ca >> rb >> cb;
      ra--;
      ca--;
      rb--;
      cb--;
      // cout << "idx(ra, ca)): " << idx(ra, ca)
      //  << ", idx(rb, cb)): " << idx(rb, cb) << endl;
      // cout << d.same(idx(ra, ca), idx(rb, cb)) << endl;
      if (d.same(idx(ra, ca), idx(rb, cb)) && red[ra][ca] && red[rb][cb])
        cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  }
}