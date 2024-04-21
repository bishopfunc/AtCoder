#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define WIDTH 10000
#define N 20
#define MAX_T 100

struct state {
  int X[N];  // 配列X
  int par_rank;  // 登録時の親の順位 (自分のはソートされてわからん)
  char type;  // 登録時の自身の操作
  int score;
};
bool operator<(state a, state b) { return a.score < b.score; }
bool operator>(state a, state b) { return a.score > b.score; }

state beams[MAX_T + 1][WIDTH + 1];
// beams[i][j] i番目の操作でj番目の候補

int T;
int P[MAX_T + 1], Q[MAX_T + 1], R[MAX_T + 1];
int candidates_nums[MAX_T + 1];  // 候補の数

void beam_search() {
  beams[0][0].score = 0;   // 0番目の操作でスコア0
  candidates_nums[0] = 1;  // 最初は1つ A,B
  for (int i = 0; i < N; i++) { beams[0][0].X[i] = 0; }  // 最初は 0000

  for (int i = 1; i <= T; i++) {
    vector<state> candidates;  // 候補
    // [i-1]から[i]に遷移するDP?
    for (int j = 0; j < candidates_nums[i - 1]; j++) {
      // 操作A
      state A = beams[i - 1][j];
      A.type = 'A';
      A.par_rank = j;
      A.X[P[i]]++;
      A.X[Q[i]]++;
      A.X[R[i]]++;
      for (int k = 0; k < N; k++) {
        if (A.X[k] == 0) A.score++;
      }
      // 操作B
      state B = beams[i - 1][j];
      B.type = 'B';
      B.par_rank = j;
      B.X[P[i]]--;
      B.X[Q[i]]--;
      B.X[R[i]]--;
      for (int k = 0; k < N; k++) {
        if (B.X[k] == 0) B.score++;
      }
      // 候補に追加
      candidates.push_back(A);
      candidates.push_back(B);
    }
    // 降順ソート
    sort(candidates.rbegin(), candidates.rend());
    // 候補の数の更新
    candidates_nums[i] = min(WIDTH, (int)candidates.size());
    // beamsの更新
    for (int j = 0; j < candidates_nums[i]; j++) beams[i][j] = candidates[j];
  }
}

int main() {
  cin >> T;
  for (int i = 1; i <= T; i++) { cin >> P[i] >> Q[i] >> R[i]; }
  beam_search();
  // DPの復元
  int rank = 0;  // 先頭が最強
  char ans[T + 1];
  for (int i = T; i >= 1; i--) {
    ans[i] = beams[i][rank].type;
    rank = beams[i][rank].par_rank;
  }
  for (int i = 1; i <= T; i++) { cout << ans[i] << endl; }
}
