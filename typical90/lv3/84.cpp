#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// oxをどちらも含む区間はむずいので
// 全体から選べる区間 - oだけ区間 - xだけ区間
// ある文字だけの区間を数字 ランレングス圧縮
// 区間の選び方は 文字数+1 C 2

ll nC2(ll n) { return n * (n - 1) / 2; }

int main() {
  int N;
  string S;
  cin >> N >> S;
  vector<int> groups;
  char ch = S[0];
  ll cnt = 0;
  for (int i = 0; i < N; i++) {
    if (ch == S[i]) {
      cnt++;
    } else {
      ch = S[i];
      groups.push_back(cnt);
      cnt = 1;
    }
  }
  if (cnt) groups.push_back(cnt); // cnt=1の時は1種類の残り、cnt=Nの時は全部同じ文字
  ll sum = nC2(N + 1);
  for (auto &group : groups) {
    sum -= nC2(group + 1);
    // cout << group << endl;
  }
  cout << sum << endl;
}