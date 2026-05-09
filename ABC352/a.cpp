#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int X, Y, Z, N;
  cin >> N >> X >> Y >> Z;
  bool ans = false;
  if((X < Z && Z < Y) || (Y < Z && Z < X)) {
    ans = true;
  }
  cout << (ans ? "Yes" : "No") << endl;
}