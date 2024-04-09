#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool vec_eq(vector<int> A, vector<int> B) {
  return A.size() == B.size() && equal(A.cbegin(), A.cend(), B.cbegin());
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N), P(N), Q(N);
  for (int i = 0; i < N; i++) A[i] = i + 1;
  for (int i = 0; i < N; i++) cin >> P[i];
  for (int i = 0; i < N; i++) cin >> Q[i];
  ll a = 1, b = 1;
  ll i = 1;
  do {
    if (vec_eq(A, P)) a = i;
    if (vec_eq(A, Q)) b = i;
    i++;
  } while (next_permutation(A.begin(), A.end()));
  cout << abs(a - b) << endl;
}