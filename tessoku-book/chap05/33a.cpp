#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100001
int A[MAX_N];

// xor_sum=0 -> 相手はxor_sumを0にできない -> 負け状態 ->後手必勝
// xor_sum!=0 -> 相手はxor_sumを0にできる -> 勝ち状態 ->先手必勝
// 同じ数の山 xor_sum=0みたいなイメージ
// 先手と同じ数取れば、後手必勝

// 山が1つの時（先手必勝）
// 山が2つでコインの数が1枚ずつの時（後手必勝）
// 山が2つでコインの数が同じ時（後手必勝）
// 山が2つでコインの数が違う時（先手必勝）

// 先手(non-zero)：上手くコインを取って、XOR sumを 0 に
// 後手(0)：どう取っても XOR sum は non-zero に
// 最終的に全てのコインがなくなり、その時 XOR sum の値は 0 なので後手の負け

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  int xor_sum = A[0];
  for (int i = 1; i < N; i++) {
    cin >> A[i];
    xor_sum = (xor_sum ^ A[i]);
  }
  cout << (xor_sum != 0 ? "First" : "Second") << endl;
}