#include <bits/stdc++.h>
using namespace std;

// MODで割ったあまりをxに保持するような構造体
template <int MOD>
struct Modulo {
  int x;
  Modulo() {};
  Modulo(int v) { x = v % MOD; }
  Modulo plus(Modulo<MOD> other) {
    Modulo<MOD> res;
    res.x = (other.x + x) % MOD;
    return res;
  }
};

int main() {
  Modulo<10> a(5), b(7);
  Modulo<10> c = a.plus(b);
  cout << c.x << endl;
}
