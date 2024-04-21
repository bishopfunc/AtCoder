#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// listはランダムアクセスできない

int main() {
  int Q;
  cin >> Q;
  deque<int> A;
  for (int i = 0; i < Q; i++) {
    int t, x;
    cin >> t >> x;
    if (t == 1) A.push_front(x);
    else if (t == 2) A.push_back(x);
    else if (t == 3) cout << A[x - 1] << endl;
  }
}