#include <bits/stdc++.h>
using namespace std;
int main(){
  int N; cin >> N;
  string tmp, res;
  set<string> st;
  for (int i = 0; i < N; i++) {
    cin >> tmp;
    st.insert(tmp);
  }
  if(st.size() == 3) res = "Three";
  if(st.size() == 4) res = "Four";
  cout << res << endl;
}