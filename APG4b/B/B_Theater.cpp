#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, l, r, res = 0; cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> l >> r;
    res += r - l + 1;
  }
  cout << res << endl;
}