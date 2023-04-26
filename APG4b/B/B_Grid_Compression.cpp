#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------

int H, W;
vector<string> input(101);

bool check() {
  rep(i, 0, H) {
    bool del_flag = true;
    rep(j, 0, W) {
      if (input[i][j] == '#') del_flag = false; // 削除できない
    }
    if (del_flag) {
      // '#'がなく、削除できるとき
      rep(n_i, i, H) swap(input[n_i], input[n_i + 1]); // 今の行から最終行まで+1ずらす
      H--; // 中身はずれたけど、Hが減ったから == 削除された
      return true;
    }
  }
  rep(j, 0, W) {
    bool del_flag = true;
    rep(i, 0, H) {
      if (input[i][j] == '#') del_flag = false;
    }
    if (del_flag) {
      rep(i, 0, H) input[i] = input[i].substr(0, j) + input[i].substr(j + 1); //input[i][j] を削除
      W--;
      return true;
    }
  }
  return false;
}

int main() {
  cin >> H >> W;
  rep(i, 0, H) cin >> input[i];
  while (check()); // 削除されたらtrueを返すから、もう一度0~H,0~W繰り返す 配列はずらしたあと(削除済み)
  rep(i, 0, H) cout << input[i] << endl;

}