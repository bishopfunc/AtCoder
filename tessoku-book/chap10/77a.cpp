#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
typedef long long ll;
#define MAX_N 100000
int N, K, L;
int A[MAX_N];

bool isOk(int score) {
  int pre = 0, cnt = 0;
  for (int i = 0; i < N; i++) {
    if (A[i] - pre >= score && L - A[i] >= score) {
      pre = A[i];
      cnt++;
    }
  }
  if (cnt >= K) return true;
  return false;
}
// Kを超えても 途中で切るのをやめれば良い
// 残りは必ずスコアより大きいから結果は変わらない

int main() {
  cin >> N >> L >> K;
  for (int i = 0; i < N; i++) { cin >> A[i]; }
  int ok = 0, ng = L;  // スコア0の範囲が1番でかい
  while (abs(ok - ng) > 1) {
    int mid = (ok + ng) / 2;
    if (isOk(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
}