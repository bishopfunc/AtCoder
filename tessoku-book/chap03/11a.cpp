#include <bits/stdc++.h>
using namespace std;

int linear_search(int A[], int N, int X) {
  int id = lower_bound(A + 1, A + N + 1, X) - A;
  if (id <= N && A[id] == X) return id;
  return -1;
}

int main() {
  int N, X;
  cin >> N >> X;
  int A[N + 1];
  int a;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  cout << linear_search(A, N, X) << endl;
}