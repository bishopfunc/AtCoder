#include <bits/stdc++.h>
using namespace std;
#define M 1'000'000'007
typedef long long ll;

ll pow(ll x, ll n) {
  if (n == 0) return 1;
  if (n % 2 == 0) {
    return pow(x * x % M, n / 2);
  }
  return pow(x % M, n - 1) * x % M;
}

int main() {
  ll m, n;
  cin >> m >> n;
  cout << pow(m, n) << endl;
}
