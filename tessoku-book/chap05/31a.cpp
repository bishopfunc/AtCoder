#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll div_a_or_b(ll a, ll b, ll x) {
  ll div_a = x / a;
  ll div_b = x / b;
  ll div_a_and_b = x / (a * b);
  ll div_a_or_b = div_a + div_b - div_a_and_b;
  return div_a_or_b;
}

int main() {
  ll N;
  cin >> N;
  cout << div_a_or_b(3, 5, N) << endl;
}