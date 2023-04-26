#include <bits/stdc++.h>
using namespace std;

int main() {
  // 再帰関数の定義
  function<int(int)> sum = [&](int n) {
    if (n == 0) {
      return 0;
    }
    return sum(n - 1) + n;
  };

  cout << sum(3) << endl;
}
