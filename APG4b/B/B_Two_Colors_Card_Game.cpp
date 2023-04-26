#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------

int main() {
  int N, M;
  vector<string> s(100), t(100);
  map<string, int> mp;
  cin >> N;
  rep(i, 0, N) cin >> s[i];
  cin >> M;
  rep(i, 0, M) cin >> t[i];

  rep(i, 0, N) {
    if (mp.count(s[i])) mp[s[i]]++;
    else mp[s[i]] = 1;
  }

  rep(i, 0, M) {
    if (mp.count(t[i])) mp[t[i]]--;
    else mp[t[i]] = -1;
  }

  int max = 0;
  for (const auto& [key, value] : mp) {
    // for (auto x: mp)
    // if (mp[x.first] > max) max = mp[x.first];
    if (mp[key] > max) max = mp[key];
    // cout << mp[key] << endl;
  }
  cout << max << endl;

}