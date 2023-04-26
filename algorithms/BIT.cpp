#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
template <typename T>
struct BIT {
  // a1, a2, ... an
  int n;
  vector<T> bit;
  BIT(int n_) : n(n_ + 1) , bit(n, 0) {};

  void add(int i, T x) {
    for (int idx = i; idx < n; i += (idx & -idx)) {
      bit[idx] += x;
    }
  }

  T sum(int i) {
    T s;
    for (int idx = i; idx > 0; i -= (idx & -idx)) {
      s += bit[idx];
    }
    return s;
  }
};


