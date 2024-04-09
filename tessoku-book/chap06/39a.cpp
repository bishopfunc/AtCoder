#include <bits/stdc++.h>
using namespace std;
#define MAX_N 300001

int main() {
  int N;
  cin >> N;
  int L, R;
  vector<pair<int, int>> arr;
  for (int i = 0; i < N; i++) {
    cin >> L >> R;
    arr.push_back(make_pair(R, L));  // 終了, 開始
    // 終了時間でソートする
    // 終了時間が速いと選択肢が増える
  }
  sort(arr.begin(), arr.end());

  int time = 0;
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    if (time <= arr[i].second) {  // 開始時間に間に合うなら
      time = arr[i].first;
      cnt++;
    }
  }
  cout << cnt << endl;
}