#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
int N, D[101];
int main() {
  vector<int> pays;
  vector<int> coins = {500, 100, 50, 10, 5, 1};
  while (true) {
    int tmp;
    cin >> tmp;
    if (tmp == 0) break;
    else pays.push_back(tmp);
  }
  for (auto pay: pays){
    int total_num = 0;
    int left = 1000 - pay;
    for (auto coin: coins){
      int num = left / coin;
      left -= num * coin;
      total_num += num;
    }
    cout << total_num << endl;
  }
}