#include <bits/stdc++.h>
using namespace std;

int sum_range(int s, int e) {
  if (s == e) return e;
  return sum_range(s, e - 1) + e;
}

int main() {
  cout << sum_range(0, 4) << endl; // 0 + 1 + 2 + 3 + 4 = 10
  cout << sum_range(5, 8) << endl; // 5 + 6 + 7 + 8 = 26
}