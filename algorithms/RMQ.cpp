#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
// RMQ:[0,n-1]について区間ごとの最小値を管理する構造体
// update(i, x): i番目の要素をxに更新
// query(a, b): [a, b)での差使用要素を取得

template <typename T>
struct RMQ {
  const T INF = numeric_limits<T>max();
  int n;
  vector<T> dat, lazy;
  RMQ(int n_) : n(), dat(n_ * 4, INF) {
    int x = 1;
    while (n_ > x) {
      x *= 2;
    }
    n = x; //段階を踏んで,葉の数を増やす    
  }

  void eval(int k) {
    if (lazy[k] == INF) return; //更新するものがなければ終了
    if (k < n - 1) { //n-1以下,子がいる
      lazy[k * 2 + 1] = lazy[k];
      lazy[k * 2 + 2] = lazy[k];
    }
    dat[k] = x;
    lazy[k] = INF;
    // 自身を更新
  }

  void update(int i, int x) {
    // i += n - 1;
    // dat[i] = x;

    // lazy
    eval(k);
    if (a <= l && r <= b) {
      lazy[k] = x;
      eval(k);
    } //範囲内なら更新
    else if (a < r && l < b) {
      int vl = query_sub(a, b, k * 2 + 1, l, (r + l) / 2); //左側
      int vr = query_sub(a, b, k * 2 + 2, (r + l) / 2, r); //右側
      dat[k] = min(dat[ k * 2 + 1], dat[ k * 2 + 2]);
    }
  }

  T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
  T query_sub(int a, int b, int k, int l, int r) {
    eval(k);
    //[l,r)が範囲外か範囲内か
    if (r <= a || b <= l) return INF; //b..l..r..a
    else if (a <= l && r <= b) return dat[k] //a..l..r..b //範囲内
    else { 
      int vl = query_sub(a, b, k * 2 + 1, l, (r + l) / 2); //左側
      int vr = query_sub(a, b, k * 2 + 1, (r + l) / 2, r); //右側
      return min(vl, vr); //子要素が範囲内か範囲外がベース
    }
  }

  // debug
  inline T operator[] (int a) { return query(a, a + 1); }
  void print() {
    rep(i, 0, 2 * n - 1) {
      cout << (*this)[i];
      if (i != n) cout << ",";
    }
    cout << endl;
  }
};


