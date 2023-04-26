#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int x, a, b;
  cin >> x >> a >> b;
  int res1, res2, res3, res4;
  // 1.
  res1 = (x + 1);
  cout << res1 << endl;
 
  // 2.
  res2 = res1 * (a + b);
  cout << res2 << endl; 

  // 3.
  res3 = res2 * res2;
  cout << res3 << endl; 

  // 4.
  res4 = res3 - 1;
  cout << res4 << endl; 
}