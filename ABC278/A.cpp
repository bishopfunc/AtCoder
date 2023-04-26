#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
int main() {
  int N, K, a;
  queue<int> A;
  cin >> N >> K;
  rep(i, 0, N) {
    cin >> a;
    A.push(a);
  }
  rep(i, 0, K) {
    A.pop();
    A.push(0);
  }
  while (!A.empty()) {
    cout << A.front() << " ";
    A.pop();
  }
  cout << endl;
}