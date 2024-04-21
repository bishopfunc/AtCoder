#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  string S, T;
  cin >> S >> T;
  transform(S.begin(), S.end(), S.begin(), ::toupper);
  int cnt = 0;
  bool ans = false;
  int l = 0, r = (int)S.size() - 1;
  for (int i = 0; i < 3; i++) {
    while (l <= r) {
      // cout << l << endl;
      if (T[i] == S[l]) {
        cnt++;
        l++;
        break;
      }
      l++;
    }
  }
  // cout << cnt << endl;
  if ((cnt == 2 && T[2] == 'X') || cnt == 3) ans = true;
  cout << (ans ? "Yes" : "No") << endl;
}