#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
int main() {
  int N; cin >> N;
  bitset<N> is_prime(0);
  rep(i, 2, N + 1) is_prime.set(i);
  rep(i, 2, N + 1) {
    if(is_prime[i]) {//2により4,6,8が消されて,2,3,5,7..
        for(int j = i * 2; j < N + 1; j += i) is_prime.reset(j); // 2なら、4,6,8...
    }
  }
}