#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------

int main() {
  string S; cin >> S;
  string vec[4] = {"dream", "dreamer", "erase", "eraser"};
  reverse(all(S));
  rep(i, 0, 4) reverse(all(vec[i])); // 逆順にして比較

  bool res_flag = true;
  int j = 0;
  while (j < (int)S.size()) {
    int count = 0;
    rep(i, 0, 4) {
      if (S.substr(j, (int)vec[i].size()) == vec[i]) {
        // cout << S.substr(i, (int)vec[i].size()) << ":" << vec[i] << endl;
        j += (int)vec[i].size();
      }
      else count++;
    }
    if(count == 4) {
      // else4回以上 = マッチする要素がない
      res_flag = false;
      break;
    }
  }
  if(res_flag) cout << "YES" << endl;
  else cout << "NO" << endl;
}