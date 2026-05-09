#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N, K;
  cin >> N >> K;
  queue<int> Q;
  int A[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    Q.push(A[i]);
  }
  int ans = 0;
  int remain_sheat = K;
  while (!Q.empty()) {
    int a = Q.front();
    // cout << "a: " << a << ", ans " << ans << endl;
    if (remain_sheat >= a) {
      remain_sheat -= a;
      Q.pop();
    } else {
      ans++;
      remain_sheat = K;
    }
  }
  ans++;
  cout << ans << endl;
}