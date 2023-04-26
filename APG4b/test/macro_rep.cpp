#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
 
int main() {
 
  int s = 2, n = 5;
 
  rep2(i, s, n) {
    cout << "Hello rep2: " << i << endl;
  }
 
  // 上のループとほとんど同じ処理
  rep(ii, n - s) {
    int i = ii + s;
    cout << "Hello rep: " << i << endl;
  }

  // repマクロのネスト
  rep(i, 2) {
    rep(j, 2) {
      cout << "i: " << i << ", j:" << j << endl;
    }
  }
}