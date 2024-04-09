#include <bits/stdc++.h>

using namespace std; 


int main() {
  queue<pair<string, int>> queue;
  string name; int time, n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> name >> time;
    queue.push(make_pair(name, time));
  }
  int sum_q = 0;
  while (!queue.empty()) {
    pair<string, int> p = queue.front(); queue.pop();
    if(p.second <= q) {
      cout << p.first << " " << sum_q + p.second << endl;
      sum_q += p.second;
    } else{
      queue.push(make_pair(p.first, p.second - q));
      sum_q += q;
    }
  }  
}

