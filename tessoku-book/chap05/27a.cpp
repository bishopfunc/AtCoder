#include <bits/stdc++.h>
using namespace std;

// gcd(33, 88) -> gcd(88, 33) -> gcd(33, 22) -> gcd(22, 11) -> gcd(11, 0)
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  int A, B;
  cin >> A >> B;
  cout << gcd(A, B) << endl;
}