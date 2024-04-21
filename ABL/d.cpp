#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define MAX_A 300001

// セグ木DP
// DP[i][j] i番目の数の最後の数がjの数
// DP[j]のみ Aiで更新した時の数列の数
// 連続じゃないが順番は守る forで回してAi+K Ai-Kの範囲のmaxを取り+1する

int op(int a, int b) { return max(a, b); }
int e() { return 0; }

int main() {
  int N, K;
  cin >> N >> K;
  int A[N];
  for (int i = 0; i < N; i++) { cin >> A[i]; }
  segtree<int, op, e> dp(MAX_A);  // 単位元で初期化 AのMAX分
  for (int i = 0; i < N; i++) {
    int x = A[i];
    int l = max(x - K, 0);
    int r = min(x + K + 1, MAX_A);  // [l, r)
    dp.set(x, dp.prod(l, r) + 1);       // 区間の最大値をset
  }
  cout << dp.all_prod() << endl;
}