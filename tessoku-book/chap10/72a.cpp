#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
typedef long long ll;

// タテヨコの順番は関係ない
// 行 少ない方を bit全探索して
// 残りを列で塗る 黒が少ない列を塗る
// 全部の黒の数を数える

void paint_row(vector<vector<char>>& tiles, const vector<int>& row_ids) {
  for (int j = 0; j < tiles[0].size(); j++) {
    for (int i : row_ids) { tiles[i][j] = '#'; }
  }
}

void paint_col(vector<vector<char>>& tiles, const vector<int>& col_ids) {
  for (int j : col_ids) {
    for (int i = 0; i < tiles.size(); i++) { tiles[i][j] = '#'; }
  }
}

// 白いタイルが多い順にソート
vector<pair<int, int>> sort_white_colum(const vector<vector<char>>& tiles) {
  vector<pair<int, int>> vec;  // num, id
  int W = tiles[0].size();
  for (int j = 0; j < W; j++) {
    int count = 0;
    for (int i = 0; i < tiles.size(); i++) {
      if (tiles[i][j] == '.') count++;
    }
    vec.push_back({count, j});
  }
  sort(vec.rbegin(), vec.rend());
  return vec;
}

int count_all_black(const vector<vector<char>>& tiles) {
  int num = 0;
  for (int i = 0; i < tiles.size(); i++) {
    for (int j = 0; j < tiles[i].size(); j++) {
      if (tiles[i][j] == '#') num++;
    }
  }
  return num;
}

int main() {
  int H, W, K;
  cin >> H >> W >> K;
  vector<vector<char>> C(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) { cin >> C[i][j]; }
  }
  int ans = 0;
  for (int bit = 0; bit < (1 << H); bit++) {
    vector<vector<char>> tmp_tiles = C;
    vector<int> row_ids;
    int remaining_steps = K;
    for (int i = 0; i < H; i++) {
      if (__builtin_popcount(bit) > K) continue;
      if (bit & (1 << i)) {
        row_ids.push_back(i);
        remaining_steps--;
      }
    }
    paint_row(tmp_tiles, row_ids);
    if (remaining_steps > 0) {
      vector<int> col_ids;
      vector<pair<int, int>> sorted_by_white_colum =
          sort_white_colum(tmp_tiles);
      for (int i = 0; i < remaining_steps && i < sorted_by_white_colum.size();
           i++) {
        col_ids.push_back(sorted_by_white_colum[i].second);
      }
      paint_col(tmp_tiles, col_ids);
    }
    ans = max(ans, count_all_black(tmp_tiles));
  }
  cout << ans << endl;
}