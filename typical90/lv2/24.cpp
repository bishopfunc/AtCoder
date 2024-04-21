#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// パリティ 偶奇性の問題
// 数列ではなく1つの整数で考えよう
// cin>>のミスでWA

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N), B(N);

  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) cin >> B[i];

  int total_diff = 0;
  for (int i = 0; i < N; i++) { total_diff += abs(A[i] - B[i]); }
  bool res = false;
  if (total_diff <= K && (K - total_diff) % 2 == 0) res = true;
  cout << (res ? "Yes" : "No") << endl;
}