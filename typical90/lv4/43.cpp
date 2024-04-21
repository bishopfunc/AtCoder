#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX_N 1000
#define INF (int)1e8

// bfs + 方向
// 両方向que 0-1BFS


char A[MAX_N][MAX_N];
int dist[MAX_N][MAX_N][4];
int H, W;

const vector<int> dx = {0, 0, -1, 1};
const vector<int> dy = {1, -1, 0, 0};

struct cell {
  int x;
  int y;
  int dir;
};

bool check_idx(int x, int y) {
  if (0 <= x && x <= H - 1 && 0 <= y && y <= W - 1) return true;
  return false;
}

void bfs(int sx, int sy, int gx, int gy) {
  deque<cell> deq;
  for (int d = 0; d < 4; d++) {
    deq.push_back({sx, sy, d});
    dist[sx][sy][d] = 0;
  }
  while (!deq.empty()) {
    cell now = deq.front();
    deq.pop_front();
    if (now.x == gx && now.y == gy) return;
    for (int d = 0; d < 4; d++) {
      int nx = now.x + dx[d];
      int ny = now.y + dy[d];
      int cost = dist[now.x][now.y][now.dir] + (now.dir == d ? 0 : 1);
      // 範囲内, 障害じゃない, 未探索(コストが低い)
      if (check_idx(nx, ny) && A[nx][ny] == '.' && cost < dist[nx][ny][d]) {
        // コストの更新 同じ向きなら0 違うなら1
        dist[nx][ny][d] = cost;
        // 同じ向きなら前に、違う向きなら後に
        if (now.dir == d) deq.push_front({nx, ny, d});
        else deq.push_back({nx, ny, d});
      }
    }
  }
}

int main() {
  cin >> H >> W;
  int sx, sy, gx, gy;
  cin >> sx >> sy >> gx >> gy;
  sx--;
  sy--;
  gx--;
  gy--;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) cin >> A[i][j];
  }
  // 初期化
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      for (int k = 0; k < 4; k++) dist[i][j][k] = INF;
    }
  }
  bfs(sx, sy, gx, gy);  // 全方向push
  int ans = INF;
  for (int d = 0; d < 4; d++) { ans = min(dist[gx][gy][d], ans); }

  cout << ans << endl;
}