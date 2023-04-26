#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
int main(){
  int N; cin >> N;
  string tmp;
  set<string> st;
  for (int i = 0; i < N; i++) {
    cin >> tmp;
    st.insert(tmp);
  }
  cout << st.size() << endl;
}