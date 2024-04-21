#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N, K;
  cin >> N >> K;
  vector<ll> AB(2 * N);
  for (int i = 0; i < N; i++) {
    ll A, B;
    cin >> A >> B;
    AB.push_back(B);      // 部分点
    AB.push_back(A - B);  // 満点との差
  };
  sort(AB.rbegin(), AB.rend());  // 降順にソート

  ll sum = 0;
  for (int i = 0; i < K; i++) sum += AB[i];
  // A/2<B より A-B < A/2
  // A-B < B 部分点の方が先に順番来るから、先頭から取れば問題ない
  cout << sum << endl;
}