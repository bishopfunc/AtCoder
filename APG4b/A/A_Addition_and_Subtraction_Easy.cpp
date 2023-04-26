#include <bits/stdc++.h>
using namespace std;
int main(){
  int A, B, res;
  string op;
  cin >> A >> op >> B;
  if (op == "+") res = A + B;
  if (op == "-") res = A - B;
  cout << res << endl;
}