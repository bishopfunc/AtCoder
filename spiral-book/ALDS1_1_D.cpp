#include <bits/stdc++.h>
using namespace std; 

int main() {
  int N; cin >> N;
  int R[N];
  for (int i = 0; i < N; i++) cin >> R[i];
  int minv = R[0];
  int max_prof = INT_MIN;
  for (int i = 1; i < N; i++) {
    max_prof = max(max_prof, R[i] - minv);
    minv = min(minv, R[i]);
  }
  // 最小値と最大利益をどちらも更新しする
  // 最小値が更新されたら、最大利益も変わる
  
  cout << max_prof << endl;
  
}