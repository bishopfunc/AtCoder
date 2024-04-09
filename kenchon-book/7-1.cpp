#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------

const vector<int> val = {500, 100, 50, 10, 5, 1}

int main() {
  int X; cin >> X;
  vector<int> a;
  rep(i, 0, 6) cin >> a[i];
  int total = 0;
  rep(i, 0, 6) {
    int each = X / val[i]
    if (a[i] < val[i]) a[i] = val[i];
    X -= each * val[i];
    total += each;
  }
  cout << total << endl;
}