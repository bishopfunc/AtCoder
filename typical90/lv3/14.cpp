#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  vector<ll> A(N), B(N);
  vector<bool> inSchool(N);
  fill(inSchool.begin(), inSchool.end(), false);
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) cin >> B[i];
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  // 学校が子供より多い場合の汎用的なケースを考える
  // 同じ距離のものはないという制約がある
  // AとBが同じ数だから、ソートして順番にペアすれば良い
  ll score = 0;
  for (int i = 0; i < N; i++) score += abs(A[i] - B[i]);
  cout << score << endl;
}