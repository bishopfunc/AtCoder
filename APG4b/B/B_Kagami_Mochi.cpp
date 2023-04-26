#include <bits/stdc++.h>
using namespace std;
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