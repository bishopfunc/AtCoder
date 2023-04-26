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
string substrBack(std::string str, size_t pos, size_t len) {
    const size_t strLen = str.length();
    return str.substr(strLen - pos, len);
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> S(N);
  set<string> T;
  string tmp;
  int res = 0;
  rep(i, 0, N) {
    cin >> S[i];
    S[i] = substrBack(S[i], 3, 3);    
  }
  rep(i, 0, M) {
    cin >> tmp;
    T.insert(tmp);
  } 
  rep(i, 0, N){
    auto itr = T.find(S[i]);
    if (itr != T.end()) res++;
  } 
  cout << res << endl;
}