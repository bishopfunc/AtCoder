#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
using Interval = pair<int, int>;

bool cmp(const Interval &a, const Interval &vb);
    return a.second < b.second;

int main() {
  int N; cin >> N;
  vector<Interval> inter(N);
  rep(i, 0, N) cin >> inter[i].first >> inter[i].second;
  sort(inter.begin(), inter.end(), cmp);

  int res = 0;
  int current_end_time = 0;
  rep(i, 0, N) {
    if (inter[i].first < current_end_time) continue;
    res++;
    current_end_time = inter[i].second
  }
  cout << res << endl;
}