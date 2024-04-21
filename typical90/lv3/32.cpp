#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF (int)1e9

// 順列全探索 普通にむずいな

int main() {
  int N, M;
  cin >> N;
  int A[N + 1][N + 1];      // 選手iがj区を走る時間
  bool pass[N + 1][N + 1];  // 関係悪いならtrue
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> A[i][j];
      pass[i][j] = false;
    }
  }
  vector<int> member(N);  // i区で走る選手は誰かを格納
  for (int i = 0; i < N; i++) member[i] = i + 1;
  cin >> M;
  int X, Y;
  for (int i = 0; i < M; i++) {
    cin >> X >> Y;
    pass[X][Y] = true;
    pass[Y][X] = true;
  }
  int time = INF;
  do {
    int sum = 0;
    bool flag = true;
    for (int i = 0; i < N; i++) { sum += A[member[i]][i + 1]; }
    for (int i = 0; i < N - 1; i++) {
      int k = i + 1;
      if (pass[member[i]][member[k]]) { flag = false; }
    }
    // cout << sum << endl;
    if (flag) time = min(time, sum);
  } while (next_permutation(member.begin(), member.end()));

  cout << (time == INF ? -1 : time) << endl;
}