#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
// vector<vector<int>> memo;

bool func(int i, int w, const vector<int>&a) {
  if (i == 0) {
    if (w == 0) return true;
    else return false;
  }
  if (func(i - 1, w, a)) return true;  
  if (func(i - 1, w - a[i - 1], a)) return true;  


  return false;
}

int main() {
  int N, W;
  // memo.assign(N, vector<int>(N, -1));
  vector<int> a(N);
  cin >> N >> W;
  rep(i, 0, N) cin >> a[i];
  if (func(N, W, a)) cout << "Yes" << endl;
  else cout << "No" << endl;
}