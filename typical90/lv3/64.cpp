#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<ll> A(N + 1), B(N + 1);
  for (int i = 1; i <= N; i++) { cin >> A[i]; }
  ll sum = 0;
  for (int i = 1; i <= N - 1; i++) {
    B[i] = A[i + 1] - A[i];
    sum += abs(B[i]);
  }
  B[0] = 0;
  B[N] = 0;

  // cout << sum << endl;
  for (int i = 0; i < Q; i++) {
    ll L, R, V;
    cin >> L >> R >> V;
    ll pre = abs(B[L - 1]) + abs(B[R]);
    // cout << "B[L-1]: " << B[L - 1] << ", B[R]: " << B[R] << endl;

    if (L >= 2) B[L - 1] += V;  // L=1を除外 B[0]はなし
    if (R <= N - 1) B[R] -= V;  // R=Nを除外 B[R]はなし
    // +-しなければ diffを増えない
    // cout << "B[L-1]: " << B[L - 1] << ", B[R]: " << B[R] << endl;
    ll post = abs(B[L - 1]) + abs(B[R]);
    // for (int i = 1; i <= N - 1; i++) sum += abs(B[i]);
    // シミュレーションは遅い、変化してるは両端だけ
    // cout << "post: " << post << ", pre: " << pre
    //  << ", post - pre: " << post - pre << endl;
    // 3回目操作と2回目の操作の差がpost-pre 
    // 3回目操作と最初のB[i]の和とは違うからそれまでの差を追加したお
    sum += (post - pre);
    cout << sum << endl;
  }
}