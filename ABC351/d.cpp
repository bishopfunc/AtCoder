#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const vector<int> dx = {0, 0, -1, 1};
const vector<int> dy = {1, -1, 0, 0};

int H, W;
int idx(int x, int y) { return x * W + y; }

int main() {
  cin >> H >> W;
  vector<vector<char>> S(H, vector<char>(W));
  vector<vector<bool>> visited(H, vector<bool>(W, false));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) { cin >> S[i][j]; }
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      for (int k = 0; k < 4; k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
        if (S[i][j] == '#') S[ni][nj] = 'X';
      }
    }
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) { cout << S[i][j]; }
    cout << endl;
  }
  map<ll, int> mp;  // 集合, 自由度
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      int id = idx(i, j);
      if (visited[i][j]) continue;
      queue<pair<int, int>> q;
      q.push({i, j});
      int free = 0;
      while (!q.empty()) {
        auto [ui, uj] = q.front();
        visited[ui][uj] = true;
        q.pop();
        free++;
        if (S[ui][uj] == '#') break;
        else if (S[ui][uj] == 'X') {
          mp[id] = free;
        } else if (S[i][j] == '.') {
          for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
            q.push({ni, nj});
          }
        }
      }
    }
  }
  int ans = 0;
  for (auto &m : mp) {
    cout << bitset<8>(m.first) << " " << m.second << endl;
    ans = max(ans, m.second);
  }
  cout << ans << endl;
}