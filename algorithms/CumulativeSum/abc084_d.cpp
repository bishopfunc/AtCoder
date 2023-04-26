#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
#define MAX 100001

int main() {
  // int N; cin >> N; 
  int N = (int)MAX;
  bitset<MAX> is_prime(0);
  rep(i, 2, N) is_prime.set(i); // i<=N
  rep(i, 2, N) { // i<=N
    if(is_prime[i]) {//2により4,6,8が消されて,2,3,5,7..
        for(int j = i * 2; j < N; j += i) is_prime.reset(j); // 2なら、4,6,8... //i*1は素数, i*2から
        // j<=N
    }
  }
  // 2017-like
  vector<int> a(N, 0); 
  rep(i, 0, N) {
    // if (a[i + 1] % 2 == 0 && a[i + 2] != 2) continue;
    if (is_prime[i] && is_prime[(i + 1) / 2]) a[i] = 1;
  }
  // sum
  vector<int> s(N + 1, 0); 
  rep(i, 0, N) s[i + 1] = s[i] + a[i];

  // input
  int Q; cin >> Q;
  rep(i, 0, Q) {
    int l, r; 
    cin >> l >> r;
    r++; //l=13,r=13 => [13, 14)
    cout << s[r] - s[l] << endl;
  }
}