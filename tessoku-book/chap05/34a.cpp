// Grudy数はXorSumの抽象化
// Grundy数が0なら負け
// Grundy数が0でないなら勝ち
// Mex: 最小除外数(Minimum excludant)
// 集合を受け取って、集合に含まれない最も小さい非負整数を返す関数
// Grundy数が正(non-zero)：上手く手を選ぶと次の状態での Grundy数を 0 にできる
// →先手必勝

// Grundy数が0：どのように手を選んでも、次の Grundy数は non - zero
//  →後手必勝

// g((0,0)) : 終了状態なので 0
// g((1,0)) = mex( {g(0,0)} ) = mex( {0} ) = 1
// g((2,0)) = mex( {g(0,0),g(1,0)} ) = mex( {0,1} ) = 2

// grudy数abcに遷移できるなら、今のgrudy数abc以外の最小の非負整数

#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100001
#define NIL -1
int A[MAX_N];
int grundy[MAX_N];

int mex(set<int> S) {
  int m = 0;
  while (S.find(m) != S.end()) {
    m++;
  }
  return m;
}

int main() {
  int N, X, Y;
  cin >> N >> X >> Y;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  fill(grundy, grundy + MAX_N, NIL);  // 0,1もここで0に初期化
  for (int i = 0; i < MAX_N; i++) {
    set<int> S;
    if (i < X && i < Y) grundy[i] = 0;
    if (i >= X) S.insert(grundy[i - X]);
    if (i >= Y) S.insert(grundy[i - Y]);
    grundy[i] = mex(S);
  }
  int xor_sum = 0;
  for (int i = 0; i < N; i++) {
    xor_sum = (xor_sum ^ grundy[A[i]]);
  }
  cout << (xor_sum != 0 ? "First" : "Second") << endl;
}