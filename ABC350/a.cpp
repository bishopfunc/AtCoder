#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  string S;
  bool ans = false;
  cin >> S;
  // int num = (S[3] - '0') * 100 + (S[4] - '0') * 10 + (S[5] - '0');
  // if (S[0] == 'A' && S[1] == 'B' && S[2] == 'C' && 1 <= num && num <= 349 &&
  // (num != 316)) ans = true;
  string abc = S.substr(0, 3);
  int num = stoi(S.substr(3, 3));
  if (abc == "ABC" && num != 316 && num >= 1 && num <= 349) ans = true;

  cout << (ans ? "Yes" : "No") << endl;
}