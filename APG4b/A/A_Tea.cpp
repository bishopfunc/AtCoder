#include <bits/stdc++.h>
using namespace std;
int main(){
  string S; cin >> S;
  bool res_flag = false;
  if (S.at((int)(S.size() - 1)) == 'T') res_flag = true;
  if (res_flag) cout << "YES" << endl;
  else cout << "NO" << endl;
}