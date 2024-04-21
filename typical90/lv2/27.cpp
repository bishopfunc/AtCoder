#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  map<string, bool> user;
  for (int i = 1; i <= N; i++) {
    string S;
    cin >> S;
    if (user.count(S) == 0) {
      user[S] = true;
      cout << i << endl;
    } else continue;
  }
}