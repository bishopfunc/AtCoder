#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// // 約数列挙
// // 10^7以下の高度合成数10810800 素因数の種類は6
// int main() {
//   int N, K;
//   cin >> N >> K;
//   vector<int> primes = {2, 3, 5, 7, 11, 13};
//   vector<int> cnts(N + 1, 0);
//   for (int i = 2; i <= N; i++) {
//     for (auto &p : primes) {
//       if (i % p == 0) cnts[i]++;
//     }
//   }
//   int ans = 0;
//   for (int i = 2; i <= N; i++) {
//     if (cnts[i] >= K) ans++;
//   }
//   cout << ans << endl;
// }

// O(NlogN)らしい i<=√Nでない
int main() {
  int N, K;
  cin >> N >> K;
  vector<int> cnts(N + 1, 0);
  for (int i = 2; i <= N; i++) {
    if (cnts[i] >= 1) continue;                 // 素数じゃない
    for (int j = i; j <= N; j += i) cnts[j]++;  // 素数の時だけ実行
  }
  int ans = 0;
  for (int i = 2; i <= N; i++) {
    if (cnts[i] >= K) ans++;
  }
  cout << ans << endl;
}