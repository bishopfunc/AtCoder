#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int res = 1;
  for (int i = 0; i < S.size(); i++) {
    
    if (S.at(i) == '+') res++;
    else if (S.at(i) == '-') res--;
  }
  cout << res << endl;
}
