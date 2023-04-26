#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));

//---------------------------------------------------------------------------------------------------

int main() {
  int H, W; cin >> H >> W;
  vector<string> G(H + 1);
  bool res_flag = true;
  string tmp;
  rep(i, 1, H + 1) {
    cin >> tmp;
    G[i] = ' ' + tmp;
  }
  int i = 1, j = 1, count = 0;
  while (true) {
    if(count > 500 * 500) {
      res_flag = false;
      break;
    }
    if(G[i][j] == 'U' && i != 1) i--;
    else if(G[i][j] == 'D' && i != H) i++;
    else if(G[i][j] == 'L' && j != 1) j--;
    else if(G[i][j] == 'R' && j != W) j++;
    else break;
    count++;
  }
  if (res_flag) cout << i << ' ' << j << endl;
  else cout << -1 << endl;
}