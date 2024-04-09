#include <bits/stdc++.h>
using namespace std;
#define MAX_N 152
#define INF (int)1e9
int X[MAX_N], Y[MAX_N];
int visited[MAX_N];
int path[MAX_N];
int N;

double getDistance(int i, int j) {
  double diffX = X[i] - X[j];
  double diffY = Y[i] - Y[j];
  return sqrt(diffX * diffX + diffY * diffY);
}

// path[i - 1]を使って全部の距離を比較して、path[i]を計算
void greedy() {
  fill(visited, visited + MAX_N, false);  // 効率的な初期化

  path[1] = 1;
  visited[1] = true;
  for (int i = 2; i <= N; i++) {
    double min_dist = INF;
    int min_id = -1;
    int pre_id = path[i - 1];
    for (int j = 1; j <= N; j++) {
      if (visited[j]) continue;
      double dist = getDistance(pre_id, j);
      if (dist < min_dist) {
        min_dist = dist;
        min_id = j;
      }
    }
    path[i] = min_id;
    visited[min_id] = true;
  }
  path[N + 1] = 1;
}

int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> X[i] >> Y[i];
  }
  greedy();
  for (int i = 1; i <= N + 1; i++) {
    cout << path[i] << endl;
  }
}
