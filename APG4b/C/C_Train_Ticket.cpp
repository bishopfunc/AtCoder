#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
int main() {
  string num; cin >> num;
  vector<int> num_vec;
  rep(i, 0, num.size()) num_vec.push_back(num[i] - '0');
  rep(i, 0, (1 << 3)) {
    int sum = num_vec[0];
    bitset<3> st(i);
    rep(j, 0, 3) {
      if(st.test(j)) sum += num_vec[j + 1];
      else sum -= num_vec[j + 1];
    }
    if (sum == 7) {
      cout << num_vec[0];
      rep(j, 0, 3) {
        string op;
        if(st.test(j)) op = "+";
        else op = "-";
        cout << op << num_vec[j + 1];
      }
      cout << "=7" << endl;
      return 0;
    }
  }
}