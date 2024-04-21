#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// ランダムで1000回足し算したAと出力手順によって足し算したBの比較
// STEP1 ランダムでも良い結果になるのでは
// STEP2 山登り方で x y h を変えていく
// STEP3 確率を焼きなまし

const int Q = 1000, N = 100;
int A[N][N], B[N][N];
int X[Q], Y[Q], H[Q];

int get_score() {
  int sum = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) { sum += abs(A[i][j] - B[i][j]); }
  }
  return 2000000000 - sum;
}

// xyhを変える = 元のxyhはマイナスされて、新しいxyhがプラスされる
void change_grid(int t, int x, int y, int h) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      B[j][i] -= max(0, H[t] - abs(X[t] - i) - abs(Y[t] - j));
    }
  }
  X[t] = x;
  Y[t] = y;
  H[t] = h;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      B[j][i] += max(0, H[t] - abs(X[t] - i) - abs(Y[t] - j));
    }
  }
}
int rand_int(int a, int b) { return a + rand() % (b - a + 1); }
double rand_double() { return 1.0 * rand() / RAND_MAX; }  //[0, 1]

void solve() {
  int TIME_LIMIT = 5.99 * CLOCKS_PER_SEC;
  int best_score = get_score();
  int start_time = clock();
  while (int new_time = (clock() - start_time) < TIME_LIMIT) {
    int t = rand_int(0, Q - 1);  // 適当にQから選んで
    int old_x = X[t], new_x = X[t] + rand_int(-9, 9);
    int old_y = Y[t], new_y = Y[t] + rand_int(-9, 9);
    int old_h = H[t], new_h = H[t] + rand_int(-19, 19);
    if (new_x < 0 || new_x > N - 1) continue;
    if (new_y < 0 || new_y > N - 1) continue;
    if (new_h < 1 || new_h > N) continue;
    change_grid(t, new_x, new_y, new_h);
    int score = get_score();
    // startT = 180 finT = 1
    double T = 180.0 - 179.0 * (new_time - start_time) / TIME_LIMIT;
    double prob = exp(min(0.0, -(best_score - score) / T)); // 悪化させる方を許す
    if (rand_double() < prob) best_score = score; // 焼きなまし
    // if (best_score < score) best_score = score;  // 山登り
    else change_grid(t, old_x, old_y, old_h);    // 戻す
  }
}

int main() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> A[i][j];
      B[i][j] = 0;
    }
  }
  for (int i = 0; i < Q; i++) {
    X[i] = rand() % N;   // 0~N-1
    Y[i] = rand() % N;   // 0~N-1
    H[i] = 1;            // 1~N
    B[Y[i]][X[i]] += 1;  // 分布を近づける
  }
  solve();
  cout << Q << endl;
  for (int i = 0; i < Q; i++) {
    cout << X[i] << " " << Y[i] << " " << H[i] << endl;
  }
}