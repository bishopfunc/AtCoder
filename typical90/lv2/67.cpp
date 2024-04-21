#include <bits/stdc++.h>

#include <regex>
using namespace std;
typedef long long ll;

// コーナケース0の時

string ntom(string num_n, ll N, ll M) {
  if (num_n == "0") return "0";
  string num_m;
  ll num_10 = 0;
  for (char &c : num_n) num_10 = (c - '0') + num_10 * N;
  while (num_10 > 0) {
    num_m = (char)((num_10 % M) + '0') + num_m;
    num_10 /= M;
  }
  return num_m;
}

int main() {
  string N;
  ll K;
  cin >> N >> K;
  while (K--) {
    N = ntom(N, 8, 9);
    // cout << N << endl;
    N = regex_replace(N, regex("8"), "5");
  }
  cout << N << endl;
}