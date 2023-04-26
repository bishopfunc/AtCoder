#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------

int main() {
  bitset<3> bt; cin >> bt;
  int count = 0;
  rep(i, 0, 3) {
    if(bt.test(i)) count++;
  }
  cout << count << endl;
}