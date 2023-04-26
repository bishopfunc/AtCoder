#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }

  bool ans = false;  
  for (int tmp = 0; tmp < (1 << 20); tmp++) {
    bitset<20> s(tmp);
    int sum = 0;

    // if(ans) break;
    for (int i = 0; i < N; i++) {
      if(s.test(i)) { sum += A.at(i); }
    }
    if(sum == K) { 
      ans = true; 
      // break; 
    }
  }

  if(ans) { cout << "YES" << endl; }
  else { cout << "NO" << endl; }
}

// breakで一回しかforを抜けてなかったのが原因っぽい