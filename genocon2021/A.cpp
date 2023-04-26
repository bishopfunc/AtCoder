#include <bits/stdc++.h>

using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
int main() {
  int N; cin >> N;
  string S;
  rep(i, 0, N) {
    cin >> S;
    reverse(all(S));
    rep(s, 0, S.size()) {
      if (S[s] == 'A') S[s] = 'T';
      else if (S[s] == 'T') S[s] = 'A';
      else if (S[s] == 'G') S[s] = 'C';
      else if (S[s] == 'C') S[s] = 'G';
    }
    cout << S << endl;
  }
}