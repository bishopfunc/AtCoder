#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX_N 100000
#define MAX_K (ll)1e9
#define INF (ll)1e9 + 1LL
vector<ll> A(MAX_N, 1);

int N;
ll K;
bool isOk(ll time) {
  ll sum = 0;
  for (int i = 0; i < N; i++) {
    sum += time / A[i];  // プリンタAiでt秒間印刷できた枚数
    // cout << "time: " << time << ", A[i]: " << A[i] << endl;
    // cout << time / A[i] << endl;
  }
  if (sum >= K) return true;
  return false;
}

int main() {
  cin >> N >> K;
  // [0, N)
  for (int i = 0; i < N; i++) { cin >> A[i]; }
  ll ok = MAX_K, ng = 0;
  // Kの最大値+1はあり得ない ある意味バンへい？
  while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    if (isOk(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
}