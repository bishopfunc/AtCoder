#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
int H, W;
string maze[501];
bool checked[501][501];
int s_x, s_y, g_x, g_y;
bool res_flag = false;
 
void search(int x, int y) {
  // cout << x << ":" << y << endl;
  if (x == g_x && y == g_y) {
    res_flag = true;
    return;
  }
  if (x < 0 || y < 0 || x >= W || y >= H || maze[y][x] == '#') return;
  if (checked[y][x]) return;
  checked[y][x] = true;
  search(x + 1, y);
  search(x - 1, y);
  search(x, y + 1);
  search(x, y - 1);
}
 
int main() {
  cin >> H >> W;
  rep(i, 0, H) cin >> maze[i];
  rep(i, 0, H) rep(j, 0, W) {
    checked[i][j] = false;
    if (maze[i][j] == 's') {
      s_x = j; 
      s_y = i; 
    }
    if (maze[i][j] == 'g'){
      g_x = j; 
      g_y = i;
    } 
  }
  // rep(i, 0, H) rep(j, 0, W) cout << maze[i][j] << endl;
  // cout << s_x <<  s_y << endl;
  search(s_x, s_y);
  if(res_flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}
