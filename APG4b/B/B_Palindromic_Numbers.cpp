#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
int main() {
  int A, B; cin >> A >> B;
  int count = 0;  
  rep(i, A, B + 1) {
    string num, rev_num;
    num = to_string(i);
    rev_num = to_string(i);
    reverse(all(rev_num));
    if (num == rev_num) count++;
  }
  cout << count << endl;
}