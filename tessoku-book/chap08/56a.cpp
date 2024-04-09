#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX_S 200001
// #define mod (int)(pow(2, 31) - 1)  // 2147483647
#define mod 2147483647
ll H[MAX_S];
ll pow100[MAX_S];
ll hash_val(int l, int r) {
  ll val = (H[r] - pow100[r - l + 1] * H[l - 1]) % mod;
  if (val < 0) val += mod;
  return val;
}

int main() {
  int N, Q;
  string S;
  cin >> N >> Q >> S;
  int a, b, c, d;
  pow100[0] = 1;
  for (int i = 1; i <= N; i++) {
    pow100[i] = (pow100[i - 1] * 100LL) % mod;
  }
  H[0] = 0;
  for (int i = 1; i <= N; i++) {
    H[i] = (H[i - 1] * 100LL + (S[i - 1] - 'a')) % mod;
  }

  for (int i = 0; i < Q; i++) {
    cin >> a >> b >> c >> d;
    // cout << hash_val(a, b) << endl;
    // cout << hash_val(c, d) << endl;
    cout << (hash_val(a, b) == hash_val(c, d) ? "Yes" : "No") << endl;
  }
}