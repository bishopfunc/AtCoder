#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N; cin >> N;
  int sum = 0;
  vector <int> v (N);
  for (int i = 0; i < N; i++) {
    cin >> v.at(i);
    sum += v.at(i);  
  }
  for (int i = 0; i < N; i++) {
    if(v.at(i) - sum / N > 0) cout << v.at(i) - sum / N << endl;
    else cout << sum / N - v.at(i) << endl;
  }
  
}