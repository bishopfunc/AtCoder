#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class BIT {
 private:
  vector<int> a;
  int N;

 public:
  BIT(int size) {
    N = size;
    a.resize(size + 1);
  }

  // a[i]にx追加する
  void add(int i, int x) {
    for (int k = i; k <= N; k += (k & -k)) { a[k] += x; }
  }

  // 1~iまで総和する
  int sum(int i) {
    int ret = 0;
    for (int k = i; k > 0; k -= (k & -k)) { ret += a[k]; }
    return ret;
  }
};

int main() {
  int N;
  cin >> N;
  // vector<int> A(N + 1);
  BIT bit(N);
  int inv_num = 0;
  vector<pair<int, int>> way;      // i-1, i
  vector<pair<int, int>> to_swap;  // 転倒数, id

  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    int cur_num = i - bit.sum(A);
    inv_num += cur_num;
    int cur_id = i + 1;
    to_swap.push_back({cur_num, cur_id});
    bit.add(A, 1);
  }
  cout << inv_num << endl;
  for (auto &sw : to_swap) {
    int num = sw.first;
    int id = sw.second;
    while (num > 0) {
      cout << id - 1 << " " << id << endl;
      num--;
      id--;
    }
  }
}