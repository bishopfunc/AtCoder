#include <bits/stdc++.h>
using namespace std;
void countingSort(vector<int> &A, vector<int> &B, int k) {
  int n = A.size() - 1;
  vector<int> C(k + 1);
  // 初期化
  for (int i = 0; i <= k; i++) {
    C[i] = 0;
  }
  // カウント
  for (int i = 1; i <= n; i++) {
    C[A[i]]++;
  }
  // 累積和
  for (int i = 1; i <= k; i++) {
    C[i] = C[i - 1] + C[i];
  }
  // 挿入
  for (int i = n; i >= 0; i--) {
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }
  // [-, 2, 5, 3, 2', 8, 3'] 前からだと [-, 2', 2, 3', 3, 5, 8] になる
  // カウントが減る前の累積和は2だから、2番目に配置される
}

int main() {
  int n;
  cin >> n;
  vector<int> A(n + 1), B(n + 1);  // A: 入力, B: 出力, C: カウント
  for (int i = 1; i <= n; i++) {
    cin >> A[i];  // 1-indexed
  }
  int k = *max_element(A.begin() + 1, A.end());
  countingSort(A, B, k);
  for (int i = 0; i < n; i++) {
    if (i) cout << " ";
    cout << B[i + 1];
  }
  cout << endl;
}