#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));

//---------------------------------------------------------------------------------------------------

int main() {
  int N;
  long long P, Q, R;
  cin >> N >> P >> Q >> R;
  vector<long long> A(N);
  vector<long long> sum(N + 1);
  map<long long, long long> mp;
  bool res_flag = false;

  rep(i, 0, N) cin >> A[i];
  sum[0] = 0;
  rep(i, 0, N) {
    sum[i + 1] = sum[i] + A[i];
  }
  // rep(i, 0, N) cout << sum[i] << endl;
  rep(i, 0, N + 1) mp[sum[i]] = 1;
  rep(i, 0, N + 1) {
    if((mp[sum[i]+P] == 1) && (mp[sum[i]+P+Q] == 1) && (mp[sum[i]+P+Q+R] == 1)) {
        res_flag = true;
        break;
    }
  }

  if (res_flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}