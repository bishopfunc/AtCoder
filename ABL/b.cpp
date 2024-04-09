#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
  ll A, B, C, D;
  cin >> A >> B >> C >> D;
  bool res = false;
  // A-BがC-Dより短いケース
  if ((A <= C && C <= B) || (A <= D && D <= B) || (C <= A && A <= D) ||
      (C <= B && B <= D))
    res = true;
  cout << (res ? "Yes" : "No") << endl;
  // A-BにA-Cが含まれる
  // A-BにB-Dが含まれる
  // A-BにB-Cが含まれる
}