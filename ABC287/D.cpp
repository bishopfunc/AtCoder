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
bool match_or_not(char a,char b){
	return a=='?' || b=='?' || a==b;
}

int main() {
  string S, T;
  cin >> S >> T;
  int size_T = (int)T.size();
  rep(i, 0, size_T + 1) {
    int j = size_T - i;
    // string _S = T.substr(i, i) + substrBack(T, j, j);
    string T_back = substrBack(T, j, j);
    string S_back = substrBack(S, j, j);
    if (match_or_not(S[i], T[i]) & match_or_not(S_back[j], T_back[j])) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}