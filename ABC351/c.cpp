#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  ll A[N];
  for (int i = 0; i < N; i++) { cin >> A[i]; }
  stack<ll> S;
  for (int i = 0; i < N; i++) {
    S.push(A[i]);
    while (S.size() >= 2) {
      ll a = S.top();
      S.pop();
      ll b = S.top();
      S.pop();
      if (a == b) S.push(a + 1);
      else {
        S.push(b);
        S.push(a);
        break;
      }
    }
  }
  cout << S.size() << endl;
}