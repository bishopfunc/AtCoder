#include <bits/stdc++.h>
#include <unordered_set>

using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
typedef long long ll;

int main() {
  ll N, Q;
  cin >> N >> Q;
  set<pair<ll, ll>> st;
  rep(i, 0, Q) {
    ll t, a, b;
    cin >> t >> a >> b;
    if (t == 1) st.insert({a, b});
    else if (t == 2) st.erase({a, b});
    else if (t == 3) {
      if( st.count({a, b}) && st.count({b, a})) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  }

}
