#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
int R, C;
string maze[501];
bool checked[501][501];
int s_x, s_y, g_x, g_y;
int dist = -1;
queue<pair<pair<int, int>, int>> que;

int search(int x, int y) {  
  que.push({{x, y}, dist});
  while (!que.empty()) {
    auto qf = que.front();
    int i = qf.first.first;
    int j = qf.first.second;
    int d = qf.second;
    que.pop();
    if (i < 0 || j < 0 || i >= C || j >= R || maze[j][i] == '#' || checked[j][i]) continue;
    if (i == g_x && j == g_y) {
      return dist;
    }
    checked[j][i] = true;
    d++; 
    dist = d;
    // cout << "i: " << i + 1 << ", j: " << j + 1<< ", dist: " << d << endl;
    que.push({{i + 1, j}, d});
    que.push({{i - 1, j}, d});
    que.push({{i, j + 1}, d});
    que.push({{i, j - 1}, d});    
  }  
  return dist;
}

int main() {
  cin >> R >> C;
  int s_x, s_y, g_x, g_y;
  cin >> s_y >> s_x >> g_y >> g_x;
  s_y--; s_x--; g_y--; g_x--;
  rep(i, 0, R) cin >> maze[i];
  rep(i, 0, R) rep(j, 0, C) {
    checked[i][j] = false;
  }  
  
  search(s_x, s_y);
  cout << dist << endl;
}