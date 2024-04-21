#include <bits/stdc++.h>
using namespace std;
// 事前計算

int main() {
  int H, W;
  cin >> H >> W;
  int A[H][W], S[H][W];
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> A[i][j];
      S[i][j] = 0;
    }
  }
  for (int i = 0; i < H; i++) {
    int sum = 0;
    for (int j = 0; j < W; j++) sum += A[i][j];
    for (int j = 0; j < W; j++) S[i][j] += sum;
  }
  for (int j = 0; j < W; j++) {
    int sum = 0;
    for (int i = 0; i < H; i++) sum += A[i][j];
    for (int i = 0; i < H; i++) S[i][j] += sum;
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (j) cout << " ";
      cout << S[i][j] - A[i][j];
    }
    cout << endl;
  }
}