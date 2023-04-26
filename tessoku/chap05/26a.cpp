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
const int limit = 300000;
vector<bool> deleted(limit);

int main() {
  int Q, X; cin >> Q;
  for (int i = 2; i <= limit; i++) deleted[i] = false; //全部f
  for (int i = 2; i * i <= limit; i++) {
    if (deleted[i]) continue; //削ったやつの倍数は削ってる
    for (int j = 2 * i; j <= limit; j += i) { //自分を割るのを防ぐ
      deleted[j] = true;
    }
  }
  rep(i, 0, Q) {
    cin >> X;
    if (!deleted[X]) cout << "Yes" << endl; //削除されてないのが素数
    else cout << "No" << endl;
  }
;}