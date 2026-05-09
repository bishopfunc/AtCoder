#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int A[9], B[9];
  int sumA = 0, sumB = 0;
  for (int i = 0; i < 9; i++) {
    cin >> A[i];
    sumA += A[i];
  }
  for (int i = 0; i < 8; i++) {
    cin >> B[i];
    sumB += B[i];
  }
  cout << sumA - sumB + 1 << endl;
}