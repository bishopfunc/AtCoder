#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main() {
  string S;
  cin >> S;
  vector<int> sa = suffix_array(S);
  vector<int> lcp = atcoder::lcp_array(S, sa);
  ll N = S.size();

  ll sum = 0;
  for (auto &s : lcp) sum += s;
  cout << N * (N + 1) / 2 - sum << endl;
  // 長さが1の部分文字列はN個
  // 長さが2の部分文字列はN-1個
  // ...
  // 長さがNの部分文字列は1個
  // lcpはiとj番目のsuffix arrayの重複部分を計算
}
