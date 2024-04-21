#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9

// スタックを使って O(N)で追加削除
// 本来ならN^2
// 古い起算日はもういらない
int main() {
  int N;
  cin >> N;
  vector<int> A(N), ans(N);
  for (int i = 0; i < N; i++) { cin >> A[i]; }
  stack<pair<int, int>> S;  // i, Ai
  ans[0] = -1;              // 初日は絶対無理
  for (int i = 1; i < N; i++) {
    int price = -INF;
    int s_date = -1;
    S.push({i - 1, A[i - 1]});  // 1日前をpush
    while (!S.empty()) {
      price = S.top().second;
      s_date = S.top().first;
      if (price <= A[i]) S.pop();
      else break;
    }
    if (S.empty()) ans[i] = -1;
    else ans[i] = s_date + 1;  // 1-index
  }
  for (int i = 0; i < N; i++) {
    if (i) cout << " ";
    cout << ans[i];
  }
  cout << endl;
}