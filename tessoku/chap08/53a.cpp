#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define rep2(i, s, n) for (int i = (s) - 1; i >= (int)(n); i--) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
//---------------------------------------------------------------------------------------------------
int main() {
  int Q; cin >> Q;
  int query, x;
  priority_queue<int, vector<int>, greater<int>> que;
  rep(i, 0, Q) {
    cin >> query; 
    if (query == 1) {
      cin >> x;
      que.push(x);
    }
    else if (query == 2) cout << que.top() << endl;
    else if (query == 3) que.pop();
  }
}