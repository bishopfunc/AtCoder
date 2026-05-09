#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  int A[N];
  for (int i = 0; i < N; i++) { cin >> A[i]; }
  int H = A[0], ans = -1;
  for (int i = 0; i < N; i++) {
    if (A[i] > H) {
      ans = i + 1;
      break;
    }
  }
  cout << ans << endl;
}