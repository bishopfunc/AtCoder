#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, K, min_num = 1000000000;
  cin >> N >> K;
  for (int tmp = 0; tmp < (1 << 10); tmp++) {
    bitset<10> s(tmp);
    int sum = 1;
    for (int i = 0; i < N; i++) {
      if (s.test(i)) sum *= 2; 
      else sum += K; 
    }
    if (sum < min_num) min_num = sum;
  }
  cout << min_num << endl;
}