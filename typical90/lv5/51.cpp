#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX_N 40

// 半分全列挙

int main() {
  int N, K;
  ll P;
  cin >> N >> K >> P;
  ll half1 = N / 2, half2 = N - half1;
  ll A[N];
  // vector<ll> vec1[MAX_N + 1], vec2[MAX_N + 1];  // 個数 [合計 合計]
  vector<ll> vec1[K + 1], vec2[K + 1];  // 個数 [合計 合計]
  for (int i = 0; i < N; i++) { cin >> A[i]; }
  for (int bit = 0; bit < (1 << half1); bit++) {
    ll cnt = 0, val = 0;
    for (int i = 0; i < half1; i++) {
      if (bit & (1 << i)) {
        cnt++;
        val += A[i];
      }
    }
    if (cnt <= K) vec1[cnt].push_back(val);  // 同じ個数のものはまとめられる
  }
  for (int bit = 0; bit < (1 << half2); bit++) {
    ll cnt = 0, val = 0;
    for (int i = 0; i < half2; i++) {
      if (bit & (1 << i)) {
        cnt++;
        val += A[i + half1];
      }
    }
    if (cnt <= K) vec2[cnt].push_back(val);  // 同じ個数のものはまとめられる
  }

  // bitが全部立ってる場合 40/2 = 20になってる場合がある
  for (int i = 0; i <= K; i++) {
    sort(vec1[i].begin(), vec1[i].end());
    sort(vec2[i].begin(), vec2[i].end());
  }

  // num1 vec1から取る個数
  // val1 vec1から取る合計
  ll ans = 0;
  for (int num1 = 0; num1 <= K; num1++) {
    int num2 = K - num1;
    for (auto &val1 : vec1[num1]) {
      ll upper = P - val1;
      // 上限を超える最小のidxを検索 [0,idx-1]が超えない組み合わせの個数
      // 0-indexなので idx-1しないでそのまま足せばいい
      ll cnt = lower_bound(vec2[num2].begin(), vec2[num2].end(), upper + 1) -
               vec2[num2].begin();
      ans += cnt;
    }
  }
  cout << ans << endl;
}