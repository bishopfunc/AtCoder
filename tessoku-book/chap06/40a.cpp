#include <bits/stdc++.h>
using namespace std;
#define MAX_A 101
typedef long long ll;

int main() {
  int N, A;
  cin >> N;
  ll bar[MAX_A];
  fill(bar, bar + MAX_A, 0);
  for (int i = 0; i < N; i++) {
    cin >> A;
    bar[A]++;
  }
  //  nC3
  ll cnt = 0;
  for (int i = 0; i < MAX_A; i++) {
    int n = bar[i];
    cnt += (n * (n - 1LL) * (n - 2LL) / 6LL);
    // cout << "cnt: " << cnt << endl;
    // cout << "n: " << n << endl;
  }
  cout << cnt << endl;
}