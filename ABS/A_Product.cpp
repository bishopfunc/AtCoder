#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------

int main() {
  int a, b;
  cin >> a >> b;
  if (a * b % 2 == 0) cout << "Even" << endl;
  else  cout << "Odd" << endl;
}