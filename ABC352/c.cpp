#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  vector<pair<ll, ll>> AB(N);
  vector<ll> A(N), B(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
    AB[i] = make_pair(A[i], B[i]);
  }
  ll sum = 0, ans = 0;
  for (int i = 0; i < N; i++) { sum += A[i]; }
  for (int i = 0; i < N; i++) { ans = max(sum - A[i] + B[i], ans); }
  cout << ans << endl;
}