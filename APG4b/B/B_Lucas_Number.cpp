#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
void lucus(int i, vector<long> &vec) {
  if(i == 0) vec[i] = 2;
  else if(i == 1) vec[i] = 1;
  else vec[i] = vec[i - 2] + vec[i - 1] ;
}

int main() {
  int N; cin >> N;
  vector<long>vec(86);
  rep(i, 0, N + 1) lucus(i, vec);
  // rep(i, 0, N) cout << vec[i] << endl;
  cout << vec[N] << endl;

}