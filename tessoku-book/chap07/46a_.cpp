#include <bits/stdc++.h>
using namespace std;
#define MAX_N 152
#define INF (int)1e9
int X[MAX_N], Y[MAX_N];
int visited[MAX_N];
int point[MAX_N];
int N;
int trial = 200000;  // 0を足しても変わらない

double getDistance(int i, int j) {
  double diffX = X[i] - X[j];
  double diffY = Y[i] - Y[j];
  return sqrt(diffX * diffX + diffY * diffY);
}

double getScore() {
  double score = 0;
  for (int i = 0; i < N; i++) {
    score += getDistance(point[i], point[i + 1]);
  }
  return score;
}

int randInt(int a, int b) { return a + rand() % (b - a + 1); }

double randDouble() { return (double)rand() / RAND_MAX; }

double getProb(int delta, double T) {
  // if (delta < 0) return 1.0;
  // return exp(-delta / T);
  return exp(min(0.0, -delta / T)); // 同じロジック
}
// 焼きなまし法
void epsilon_greedy() {
  point[1] = 1;
  for (int i = 2; i <= N; i++) {
    point[i] = i;
  }
  point[N + 1] = 1;

  double minScore = getScore(); // 最初の基準点
  for (int i = 0; i < trial; i++) {
    int R = randInt(2, N);  // 1,2 ... N,N+1
    int L = randInt(2, N);
    if (R < L) swap(R, L);
    reverse(point + L, point + R + 1);  // [L, R)
    double score = getScore();
    double delta = score - minScore;
    double T = getT(i);
    double prob = getProb(delta, T);

    if (randDouble() < prob) {
      minScore = score;
    } else {
      reverse(point + L, point + R + 1);  // [L, R)
    }
  }
}

int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> X[i] >> Y[i];
  }
  hill_climbing();
  for (int i = 1; i <= N + 1; i++) {
    cout << point[i] << endl;
  }
}
