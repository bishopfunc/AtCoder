#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100000
#define INF (int)1e9

class SegmentTree {
 public:
  int siz;  //  葉の数
  // int dat[MAX_N * 3];
  vector<int> dat;
  SegmentTree(int n) {
    siz = 1;
    while (siz < n) siz *= 2;  // 最小の2のべき乗数を計算 5 -> 8
    // 葉の数の2n-1が配列のサイズ 8*2-1=15
    // for (int i = 1; i <= siz * 2 - 1; i++) {
    //   dat[i] = 0;  // 最初は全て0(問題)
    // }
    dat = vector<int>(siz * 2 - 1, 0);
  }

  void update(int pos, int x) {
    // 0-indexed
    pos = pos + siz - 1;  // 葉のノードの位置 0->0+8=8 1->1+8=9
    dat[pos] = x;
    // 最小の位置は1だから>=2まで
    while (pos >= 2) {
      pos = pos / 2;                                   // 親の位置
      dat[pos] = max(dat[pos * 2], dat[pos * 2 + 1]);  // 親の値は子の大きい方
    }
  }
  // [1, 9) max(1~8) // 1から見る
  int query(int l, int r) { return query_sub(l, r, 1, siz + 1, 1); }
  // [l,r)の最小値を求める[a, b)は今見ている範囲 kは今見ているノード
  int query_sub(int l, int r, int a, int b, int k) {
    // cout << "l: " << l << " r: " << r << " a: " << a << " b: " << b << " k: "
    // << k << endl;
    if (r <= a || b <= l) return -INF;
    if (l <= a && b <= r) return dat[k];
    int m = (a + b) / 2;
    int vl = query_sub(l, r, a, m, k * 2);
    int vr = query_sub(l, r, m, b, k * 2 + 1);
    return max(vl, vr);
  }
};

int main() {
  int N, Q;
  cin >> N >> Q;
  SegmentTree st(N);
  for (int i = 0; i < Q; i++) {
    int query;
    cin >> query;
    if (query == 1) {
      int pos, x;
      cin >> pos >> x;
      st.update(pos, x);
    } else if (query == 2) {
      int l, r;
      cin >> l >> r;
      cout << st.query(l, r) << endl;
    }
  }
}