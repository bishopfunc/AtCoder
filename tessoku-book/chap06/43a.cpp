#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9

int main() {
  int N, L;
  cin >> N >> L;
  int A;
  string B;
  int max_time = -INF;
  for (int i = 0; i < N; i++) {
    cin >> A >> B;
    if (B == "E")
      max_time = max(max_time, L - A);
    else if (B == "W")
      max_time = max(max_time, A);
  }
  cout << max_time << endl;
}