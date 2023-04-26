#include <bits/stdc++.h>
using namespace std;

// 正しい移動かを調べる
bool is_valid_move(vector<string> &board, vector<vector<bool>> &checked, int x, int y) {
  int N = board.size();
  if (x <= -1 || x >= N || y <= -1 || y >= N) return false; // 枠を超える場合
  if (board.at(y).at(x) == '#') return false; // 壁のとき
  if (checked.at(y).at(x) == true) return false; // すでにチェック済みなら中止
  return true;
}

// いる状態からゴールに到達できるか
bool reachable(vector<string> &board, vector<vector<bool>> &checked, int x, int y) {
  int N = board.size();
  if (x == N - 1 && y == N - 1) return true; // ベースケース
  // 再帰ステップ
  checked.at(y).at(x) = true; // 調べたかどうかのフラグ

  bool result = false; // ゴールできるかどうかのフラグ
  if (is_valid_move(board, checked, x, y - 1) && reachable(board, checked, x, y - 1)) result = true;
  if (is_valid_move(board, checked, x + 1, y) && reachable(board, checked, x + 1, y)) result = true;
  if (is_valid_move(board, checked, x, y + 1) && reachable(board, checked, x, y + 1)) result = true;
  if (is_valid_move(board, checked, x - 1, y) && reachable(board, checked, x - 1, y)) result = true;
  return result;
}

int main() {
  int N;
  cin >> N;
  vector<string> board(N);
  for (int i = 0; i < N; i++) {
    cin >> board.at(i);
  }
  vector<vector<bool>> checked(N, vector<bool>(N, false));
  if (reachable(board, checked, 0, 0)) cout << "Yes" << endl;
  else cout << "No" << endl;
}