// しゃくとり法
// https://qiita.com/drken/items/ecd1a472d3a0e7db8dce

#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100001
typedef long long ll;

int main() {
  int N, K;
  cin >> N >> K;
  ll A[MAX_N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  ll pair = 0;
  int right = 0;
  for (int left = 0; left < N; left++) {
    while (right < N && (A[right] - A[left]) <= K) {
      right++;
    }
    // right は条件を満たさない最初の要素を指しているため、
    // left から right までの要素数をペアの数に加算する
    // 条件を満たしたら、r++するから、最終的には条件を満たさない
    // l=3, r=7 7-3-1=3
    // l=4, r=7 7-4-1=2
    // l=5, r=7 7-5-1=1
    // l=6, r=7 7-6-1=0
    pair += right - left - 1;  // 自分自身を除外するため -1 する
  }
  cout << pair << endl;
}
