#include <bits/stdc++.h>
using namespace std;
#define M 10000
int main() {
  int N;
  cin >> N;
  string T;
  int A;
  int sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> T >> A;
    if (T == "+") {
      sum += A;
    } else if (T == "*") {
      sum *= A;
    } else if (T == "-") {
      sum -= A;
    }
    if (sum < M) sum += M;
    sum %= M;
    cout << sum << endl;
  }
}