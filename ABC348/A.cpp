#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cout << (i % 3 == 0 ? "x" : "o");
  }
  cout << endl;
}