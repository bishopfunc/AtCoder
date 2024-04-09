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

int main() {
  ll a, b;
  cin >> a >> b;
  cout << power(a, b) << endl;
  ;
}