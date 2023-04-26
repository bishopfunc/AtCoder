#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
int main() {
  int N; cin >> N;
  rep(i, 0, (1 << N)) {
    bitset<200000>st(i);
    st >> i;
    if(st.count() % 2 == 1) {
      rep(j, 0, (1 << N))
    }
  }
}