#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
typedef long long ll;

ll power(ll a, ll b) {
  a %= M;
  if (b == 0) return 1;
  if (a == 0) return 0;
  if (b % 2 == 0) return power(a * a, b / 2) % M;
  return a * power(a, b - 1) % M;
}

// a / b  % M = (a * b(M - 2)) % M
ll divide_mod(ll a, ll b) {
  a %= M;
  b %= M;
  return (a * power(b, M - 2)) % M;
}

// nCr = n! / r! (n - r)!
ll combination(ll n, ll r) {
  // n!
  ll a = 1;
  for (int i = 1; i <= n; i++) {
    a = i * a % M;
  }
  ll b = 1;
  // r!
  for (int i = 1; i <= r; i++) {
    b = i * b % M;
  }
  // (n - r)!
  for (int i = 1; i <= n - r; i++) {
    b = i * b % M;
  }
  return divide_mod(a, b);
}

int main() {
  int n, r;
  cin >> n >> r;
  cout << combination(n, r) << endl;
}