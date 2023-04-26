#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
int main() {
  int N, Q;
  string S;
  cin >> N >> Q >> S;
  vector<int> s(N + 1, 0);
  rep(i, 0, N) {
    if (S[i] == 'A' && S[i + 1] == 'C') s[i + 1] = s[i] + 1;
    else s[i + 1] = s[i];
  }

  rep(i, 0, Q) {
    int l, r;
    cin >> l >> r;
    l--; r--; //0-indexed
    cout << s[r] - s[l] << endl;
  }
}