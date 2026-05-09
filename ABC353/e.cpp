#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  vector<string> A(N);
  vector<vector<int>> sa_dp(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    sa_dp[i] = suffix_array(A[i]);
  }

  vector<int> lcp = atcoder::lcp_array(S, sa);
}
