#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------

int main() {
  string S; cin >> S;
  int N = S.length();
  long long res = 0;
  rep(bit, 0, (1 << N)) {
    long long sum = 0;
    bitset<10> st(bit);
    long long a = S[0] - '0';
    // cout << a << endl;
    rep(j, 0, N - 1) {
      if (st.test(j)) {
        sum += a;
        a = 0;
      } // 後ろが+なら答えに追加、クリア
      a = a * 10 + S[j + 1] - '0'; // 10倍して次の数字を加える(0でクリアされたら影響はない)
      // cout << a << endl;
    }
    sum += a; // 最後の数字の前が+(a=0)でもoでも対応できる
    res += sum;
  }
  cout << res / 2 << endl;
}