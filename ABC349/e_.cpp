#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF (ll)1e9 + 1

int main() {
  ll A[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) { cin >> A[i][j]; }
  }
  ll sumA = 0, sumB = 0, tmpi, tmpj;
  sumA += A[1][1];
  ll tmp = A[0][0];
  A[0][0] = INF;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (A[i][j] > tmp && A[i][j] != INF) {
        tmp = A[i][j];
        tmpi = i;
        tmpj = j;
      }
    }
  }
  sumB += tmp;
}