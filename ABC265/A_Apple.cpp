#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
int main() {
  int N, X, Y;
  cin >> X >> Y >> N;
  int num_x = N % 3;
  int num_y = (N - num_x) / 3;
  int res1 = num_x * X + Y * num_y;
  int res2 = N * X;
  cout << min(res1, res2) << endl;
}
