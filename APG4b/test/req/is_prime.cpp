#include<bits/stdc++.h>
using namespace std;

bool has_devisor(int n, int i) {
  if (n == i) return false;
  if (n % i == 0) return true;
  return has_devisor(n, i + 1);
}

bool is_prime(int n) {
  if (n == 1) return false;
  else if (n == 2) return true;
  else return !(has_devisor(n, 2));
}

int main() {
  cout << is_prime(1) << endl;  // 0
  cout << is_prime(2) << endl;  // 1
  cout << is_prime(12) << endl; // 0
  cout << is_prime(13) << endl; // 1
  cout << is_prime(57) << endl; // 0
}