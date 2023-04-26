#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
int main() {
  int N, M;
  int x, y;
  cin >> N >> M;
  vector<vector<int>> vec(N, vector<int>(N, 0));
  rep(i, 0, M) {
    cin >> x >> y;
    vec[y - 1][x - 1]++;
    vec[x - 1][y - 1]++;
    // 同じ都市間でも複数回
  }

  rep(i, 0, N) {
    int sum = 0;
    rep(j, 0, N) {
      if (vec[i][j] != 0) sum += vec[i][j];
      // 合計回数をカウント
    }
    cout<< sum << endl;
  }
}

