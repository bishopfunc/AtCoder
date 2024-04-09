#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
bool P(int x) {

}

int binary_search() {
  int l, r; //P(l) = false, P(r)=true
  while (r - l > 1) {
    int m = l + (r - l) / 2;
    if(P(m)) r = m;
    else l = m;
  }
  return r;
}