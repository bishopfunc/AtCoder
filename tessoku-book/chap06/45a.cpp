#include <bits/stdc++.h>
using namespace std;
#define MAX_N 200001

// W: 0
// B: 1
// R: 2
// WW->W 0->0 0
// BB->R 2->2 0
// RR->B 4->1 -3
// WB->B 1->1 0
// WR->R 2->2 0
// RB->B 3->1 -2

// どんな順番で合成しても同じ結果になる 最後の2枚の合計スコアだけで分類する
// 規則を見つけるゲーム
int main() {
  int N;
  string C, A;
  cin >> N >> C >> A;
  int score = 0;
  for (int i = 0; i < N; i++) {
    if (A[i] == 'W')
      score += 0;
    else if (A[i] == 'B')
      score += 1;
    else if (A[i] == 'R')
      score += 2;
  }
  bool ans = false;
  if (score % 3 == 0 && C == "W")
    ans = true;
  else if (score % 3 == 2 && C == "R")
    ans = true;
  else if (score % 3 == 1 && C == "B")
    ans = true;
  cout << (ans ? "Yes" : "No") << endl;
}