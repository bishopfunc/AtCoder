#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// しゃくとり法

int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N);
  for (int i = 0; i < N; i++) { cin >> A[i]; }
  int max_type_len = 0;
  map<ll, int> m;
  // [left, right)を保つ
  for (int left = 0, right = 0; left < N; left++) {
    // Kに影響しないならば map追加OK
    // r++する前に A[r]を見ておく
    while (right < N &&
           (m.size() < K || (m.size() == K && m.count(A[right]) > 0))) {
      m[A[right]]++;
      right++;
      // cout << "l: " << left << ", r: " << right << ", size: " << m.size()
          //  << endl;
    }
    // 更新
    max_type_len = max(max_type_len, right - left);
    // leftが次のループでずれるから減らす
    m[A[left]]--;
    // m.sizeに影響しないように減らす
    if (m[A[left]] == 0) { m.erase(A[left]); }
    // 逆転しないように 先頭でも同じ
    if (right == left) right++;
  }
  cout << max_type_len << endl;
}