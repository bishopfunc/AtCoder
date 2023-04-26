#include <bits/stdc++.h>
using namespace std;
int main(){
  string A, B, res; cin >> A >> B;
  if (A.size() > B.size()) res = A;
  else res = B;
  cout << res << endl;
}