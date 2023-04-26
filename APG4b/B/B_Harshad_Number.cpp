#include <bits/stdc++.h>
using namespace std;
int main() {
  string N; cin >> N;
  int fx = stoi(N);
  int x = 0;
  bool res_flag = false;
  for (int i = 0; i < N.size(); i++) {
    x += (int)(N.at(i) - '0');
  }
  if (fx % x == 0) res_flag = true;
  
  if (res_flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}