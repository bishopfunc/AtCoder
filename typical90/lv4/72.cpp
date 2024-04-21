#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX_N 16
#define INF (int)1e8
// DFSでバックトラック

char C[MAX_N][MAX_N];
const vector<int> dx = {0, 0, -1, 1};
const vector<int> dy = {1, -1, 0, 0};
bool finished[MAX_N][MAX_N];

int H, W;

bool check_idx(int x, int y) {
  if (0 <= x && x <= H - 1 && 0 <= y && y <= W - 1) return true;
  return false;
}

int dfs(int sx, int sy, int gx, int gy) {
  // スタートとゴールが同じ AND ゴール(=スタート)がすでに探索済み ゴールに到着
  // 再帰の底 スタートとゴールが同じ AND 最初の一回 OK
  if (sx == gx && sy == gy && finished[gx][gy] == true) return 0;
  finished[gx][gy] = true;
  int max_dist = -INF;  // 4方向で最大を返したい
  for (int d = 0; d < 4; d++) {
    int nx = gx + dx[d], ny = gy + dy[d];
    // 範囲内かつ、障害じゃないかつ、未探索(スタートは除く 閉路が作れない)
    if (check_idx(nx, ny) == false || C[nx][ny] == '#') continue;
    if (finished[nx][ny] == true && !(sx == nx && sy == ny)) continue;
    // if ((sx != nx || sy != ny) && finished[nx][ny] == true) continue;
    int ret = dfs(sx, sy, nx, ny);  // sx syは残すのでバックトラックができる
    max_dist = max(max_dist, ret + 1);  // 距離 +1
  }
  // 抜ける時に探索可能に戻す
  // 再起関数から戻ってるから、それ以下もクリアされてるはず
  finished[gx][gy] = false;
  // 更新するのはゴールは訪問済みか ゴールを伸ばして戻す
  return max_dist;
}

int main() {
  cin >> H >> W;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) { cin >> C[i][j]; }
  }
  int ans = -INF;
  // 16x16なので、全部マスからスタートしてみる
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (C[i][j] == '#') continue;
      ans = max(ans, dfs(i, j, i, j));
    }
  }
  cout << (ans <= 2 ? -1 : ans) << endl;
  // 2の時は1マス往復 -INFはなし
}