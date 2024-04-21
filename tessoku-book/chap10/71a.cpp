#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
typedef long long ll;

int main() {
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) { cin >> A[i]; }
  for (int i = 0; i < N; i++) { cin >> B[i]; }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  reverse(B.begin(), B.end());
  // 最小 x 最大 の合計が1番小さい
  int sum = 0;
  for (int i = 0; i < N; i++) { sum += A[i] * B[i]; }
  cout << sum << endl;
}