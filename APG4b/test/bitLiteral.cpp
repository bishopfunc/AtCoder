#include <bits/stdc++.h>
using namespace std;
 
int main() {
  uint32_t x = 0b100;
  cout << x << endl;  // 4
  cout << 0b010 << endl;  // 4
 
  cout << (x | 0b010) << endl;  // 計算結果は 0b110 = 6

  cout << (x + 0b010) << endl;  // 同じ
  cout << (x - 0b010) << endl;  // 四則計算OK
}