#include <bits/stdc++.h>
using namespace std;

int main() {
  // 3ビットのビット列をすべて列挙する
  cout << (1 << 3) << endl;
  cout << (1 << 4) << endl;
  cout << (0 << 3) << endl;
  cout << (0 << 4) << endl;
  cout << (5 << 3) << endl;
  cout << (5 << 4) << endl;
  cout << (1 >> 3) << endl;
  cout << (1 >> 4) << endl;
  cout << (0 >> 3) << endl;
  cout << (0 >> 4) << endl;
  cout << (80 >> 3) << endl;
  cout << (80 >> 4) << endl;
  // n << k = n * 2^k
  // n >> k = n / 2^k
  for (int tmp = 0; tmp < (1 << 3); tmp++) {
    bitset<3> s(tmp);
    // ビット列を出力
    cout << s << endl;
  }
}
