#include <bits/stdc++.h>
using namespace std;
#define MAX_X 300000
int main() {
  int Q;
  cin >> Q;
  int sqrtX = sqrt(MAX_X);
  vector<bool> prime(MAX_X, true);
  prime[0] = false;
  prime[1] = false;
  for (int i = 2; i <= sqrtX; i++) {
    if (!prime[i]) continue;
    for (int j = i + i; j <= MAX_X; j += i) {
      prime[j] = false;
    }
  }
  for (int i = 0; i < Q; i++) {
    int x;
    cin >> x;
    cout << (prime[x] ? "Yes" : "No") << endl;
  }
}