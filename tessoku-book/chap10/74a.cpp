#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
typedef long long ll;

// 転倒数の計算はN^2
// BITを使うとNlogN
// XとYは別々にソートできる
// 転倒数 = 入れ替えの回数

// https://qiita.com/DaikiSuyama/items/7295f5160a51684554a7
// https://scrapbox.io/pocala-kyopro/%E8%BB%A2%E5%80%92%E6%95%B0
// LSB(Least Significant Bit)
// 二進数で表現した時に初めて1が出てくるのは右から数えて何番目か
// k&-kでkのLSBを計算できる 010(2)&110(-2)=010
// sum(7) i~0
// 0111 - 0001 => 0110 - 0100 => 0110 - 0100 => 0000
// 7 - 1 => 6 - 2 => 4 - 4 =>
// add(5, x) i~n
// 0101 + 0001 => 0110 + 0010 => 1000
// 5 + 1 => 6 + 2 => 8

// bitは1-index
class BIT {
 private:
  vector<int> a;
  int N;

 public:
  BIT(int size) {
    N = size;
    a.resize(size + 1);
  }

  // a[i]にx追加する
  void add(int i, int x) {
    for (int k = i; k <= N; k += (k & -k)) { a[k] += x; }
  }

  // 1~iまで総和する
  int sum(int i) {
    int ret = 0;
    for (int k = i; k > 0; k -= (k & -k)) { ret += a[k]; }
    return ret;
  }
};

int main() {
  int N;
  cin >> N;
  int P[N][N], X[N], Y[N];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> P[i][j];
      if (P[i][j] != 0) {
        X[i] = P[i][j];
        Y[j] = P[i][j];
      }
    }
  }
  // int inv_num_X = 0, inv_num_Y = 0;
  // for (int i = 0; i < N; i++) {
  //   for (int j = i + 1; j < N; j++) {
  //     if (X[i] > X[j]) inv_num_X++;
  //     if (Y[i] > Y[j]) inv_num_Y++;
  //     // Xi < Xj じゃないペアは転倒数
  //   }
  // }
  int inv_num_X = 0, inv_num_Y = 0;
  BIT bitX(N), bitY(N);
  for (int i = 0; i < N; i++) {
    inv_num_X += i - bitX.sum(X[i]);
    inv_num_Y += i - bitY.sum(Y[i]);
    bitX.add(X[i], 1);
    bitY.add(Y[i], 1);
  }

  // 座標圧縮 + BITもあり
  // 自分の位置に1を追加
  // 追加した数 - 自分の左の総和 =  自分の右の総和
  // (自分より前に出てきて&自分より大きい = 転倒数)
  cout << inv_num_X + inv_num_Y << endl;
}