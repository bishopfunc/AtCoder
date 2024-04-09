#include <bits/stdc++.h>
using namespace std;

#define MAX_N 301
#define MAX_AB 101
int N, K;

int A[MAX_N], B[MAX_N];

// [a, b]のが範囲の人数をカウントする
int getScore(int a, int b) {
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    if (a <= A[i] && A[i] <= a + K && b <= B[i] && B[i] <= b + K) cnt++;
  }
  return cnt;
}

int main() {
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }
  int score = 0;
  // 1 <= A,B <= 100
  for (int i = 1; i < MAX_AB; i++) {
    for (int j = 1; j < MAX_AB; j++) {
      score = max(getScore(i, j), score);
    }
  }
  cout << score << endl;
}