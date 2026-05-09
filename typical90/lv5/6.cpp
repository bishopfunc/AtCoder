#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF (int)1e9
// 辞書順貪欲法
// 次の最小文字の場所を格納する配列は、色んな場所で使えるっぽい
// nex[i]['a'] 文字のi文字以降で'a'が最小に出てくる場所
// 後ろから計算するとコピーできる
// abcd
// dから見たらnxt[3]['d']
// cから見たらnxt[2]['d']はコピー nex[2]['c']のみ更新
// https://zenn.dev/naoya_ito/articles/24dc1117d3fe93
// https://drken1215.hatenablog.com/entry/2021/10/10/195200

int main() {
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;
  int nex[N + 1][26];  // 最初のNからN-1へのコピー用に
  // 最小値なので 最初は大きい値で埋める
  for (int i = N; i >= 0; i--) {
    for (char c = 'a'; c <= 'z'; c++) { nex[i][c - 'a'] = INF; }
  }
  // 前計算
  for (int i = N - 1; i >= 0; i--) {
    for (char c = 'a'; c <= 'z'; c++) {
      if (S[i] == c) {
        nex[i][S[i] - 'a'] = i;  // その文字は更新 //同じ文字は上書き
      } else {
        nex[i][c - 'a'] = nex[i + 1][c - 'a'];  // コピー
      }
    }
  }

  int pos = 0;
  string ans = "";
  // kは作った文字の長さ
  for (int k = 1; k <= K; k++) {
    for (char c = 'a'; c <= 'z'; c++) {
      int n_pos = nex[pos][c - 'a'];
      // cout << "k: " << k << ", c: " << c << ", pos:" << pos
      //  << ", n_pos:" << n_pos << endl;
      // 今見てるposより右にK-k文字残っていたら
      // a-zの順につよいから最小値は比較しなくていい
      if (N - 1 - n_pos >= K - k && n_pos != INF) {
        ans += c;
        pos = n_pos + 1;
        // posは何文字目を見てるか、次のループは+1文字を見る
        break;
      }
    }
  }
  cout << ans << endl;
}