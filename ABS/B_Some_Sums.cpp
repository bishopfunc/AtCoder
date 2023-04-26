#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
int sum_digits(int n) {
  string str_num = to_string(n);
  int sum = 0;
  rep(i, 0, str_num.size()) {
    sum += str_num[i] - '0';
  }

  return sum;
}

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  int sum = 0;
  rep(i, 1, N + 1) {
    if (sum_digits(i) >= A && sum_digits(i) <= B) {
      sum += i;
    }
  }
  cout << sum << endl;
}