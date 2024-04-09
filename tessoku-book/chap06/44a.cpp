#include <bits/stdc++.h>
using namespace std;
#define MAX_N 200001

int main() {
  int N, Q;
  int A[MAX_N];
  cin >> N >> Q;
  int query, x, y;
  bool state = true;
  for (int i = 1; i <= N; i++) {
    A[i] = i;
  }

  for (int i = 0; i < Q; i++) {
    cin >> query;
    if (query == 1) {
      cin >> x >> y;
      if (state)
        A[x] = y;
      else
        A[N - x + 1] = y;
    } else if (query == 2) {
      state = !state;
    } else if (query == 3) {
      cin >> x;
      if (state)
        cout << A[x] << endl;
      else
        cout << A[N - x + 1] << endl;
    }
  }
}