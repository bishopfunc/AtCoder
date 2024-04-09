#include <bits/stdc++.h>
using namespace std;
#define MAX (int)1e8
bitset<MAX> primeArray;

// bool isPrime(int x) {
//   if (x < 2) return false;
//   if (x == 2) return true;
//   for (int i = 3; i < x; i++) {
//     if (x % i == 0) return false;
//   }
//   return true;
// }

// bool isPrime(int x) {
//   if (x == 2) return true;  // x = 2の場合は先にreturn true
//   if (x < 2 || x % 2 == 0) return false;
//   for (int i = 3; i <= sqrt(x); i += 2) {
//     if (x % i == 0) return false;
//   }
//   return true;
// }

void eratos(int n) {
  primeArray.set();  // 全てのビットを1にする
  primeArray[0] = primeArray[1] = false;
  // 1個目の素数だけ残して、倍数を消していく
  int sqrtN = sqrt(n);
  for (int i = 2; i <= sqrtN; i++) {
    if (primeArray[i]) {
      for (int j = i * 2; j <= n; j += i) {
        primeArray[j] = false;
      }
    }
  }
}

int main() {
  int n, cnt = 0;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) cin >> A[i];
  int max = *max_element(A.begin(), A.end());
  eratos(max);
  for (int i = 0; i < n; i++) {
    if (primeArray[A[i]]) cnt++;
  }
  cout << cnt << endl;
}
