#include <bits/stdc++.h>
#include <unordered_set>

using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
int main() {
  int N;
  cin >> N ;
  vector<string> S(N);
  vector<string> C1 = {"H" , "D" , "C" , "S"};
  vector<string> C2 = {"A" , "2" , "3" , "4" , "5" , "6" , "7" , "8" , "9" , "T" , "J" , "Q" , "K" };

  rep(i, 0, N) cin >> S.at(i);
  bool resFlag = true;
  unordered_set<string> distinct(all(S));
  rep(i, 0, N) {
    if (S.size() != distinct.size()) {resFlag = false; break;}
    if (find(all(C1), S.at(i).substr(0,1)) == C1.end()) {resFlag = false; break;}
    if (find(all(C2), S.at(i).substr(1,1)) == C2.end()) {resFlag = false; break;}
  }
  if (resFlag) cout << "Yes" << endl;
  else cout << "No" << endl; 
}