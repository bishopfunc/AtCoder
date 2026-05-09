#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  string S, T;
  vector<int> ans;
  cin >> S >> T;
  int idx = 0;
  int right = 0;
  for (int left = 0; left < S.size(); left++) {
    while (right < T.size() && S[left] != T[right]) { right++; }
    ans.push_back(right);
    right++;
  }
  for (int i = 0; i < ans.size(); i++) {
    if (i) cout << " ";
    cout << ans[i] + 1;
  }
  cout << endl;
}