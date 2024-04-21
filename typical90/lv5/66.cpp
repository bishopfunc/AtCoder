#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 期待値の線形性
// 期待値の合計はそれぞれ計算して合計すればいい
// 2つの転倒数を見ていく N^2
// O(N^2 * L * R) N=100だから余裕

int main() {
  int N;
  cin >> N;
  int L[N], R[N];
  double num[N];
  vector<int> A_candidates[N];
  for (int i = 0; i < N; i++) {
    cin >> L[i] >> R[i];
    num[i] = R[i] - L[i] + 1;
    int l = L[i], r = R[i];
    while (l <= r) {
      A_candidates[i].push_back(l);
      l++;
    }
  }
  double ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      double inv_num = 0;
      for (auto a : A_candidates[i]) {
        for (auto b : A_candidates[j]) {
          if (a > b) inv_num++;
        }
      }
      ans += inv_num / (num[i] * num[j]);
    }
  }

  printf("%.12f\n", ans);
}