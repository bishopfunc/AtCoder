#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
typedef long long ll;
using Graph = map<ll, vector<ll>>;

int main() {
  int N, a, b;
  cin >> N;
  Graph G;
  rep(i, 0, N) {
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  queue<ll> que;
  set<ll> S;
  que.push(1); //1階から始まるから、G[1]なかったら終了！！てんさい！！
  S.insert(1); 
  while (!que.empty()) {
    ll v = que.front();
    que.pop();
    for (auto next_v : G[v]) {
      if (!S.count(next_v)) { //set countの方が早い, setはソートしてくれる
        que.push(next_v);
        S.insert(next_v);
      }
    }
  }  
  cout << *S.rbegin() << endl;
}
