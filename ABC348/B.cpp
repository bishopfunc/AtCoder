#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define INF (int)1e9

double distance(int x1, int x2, int y1, int y2) {
  return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
  int N;
  cin >> N;
  vector<int> X(N + 1), Y(N + 1);
  for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i];
  for (int i = 1; i <= N; i++) {
    double max_distance = -INF;
    int max_id = 1;
    for (int j = 1; j <= N; j++) {
      double d = distance(X[i], X[j], Y[i], Y[j]);
      if (d > max_distance) {
        max_distance = d;
        max_id = j;
      }
    }
    cout << max_id << endl;
  }
}
