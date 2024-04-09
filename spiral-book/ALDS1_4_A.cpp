#include <bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int> array, int key) {
  int n = array.size();
  array.push_back(key);
  int i = 0;
  while (array[i] != key) {
    i++;
  } // ループ終了後にi==nならkeyは見つからなかった iがkeyのindex
  return i != n; 
}

int main() { 
  int n, q; 
  cin >> n;
  vector<int> S(n);
  for (int i = 0; i < n; i++) {
    cin >> S[i];
  }
  cin >> q;
  vector<int> T(q);
  for (int i = 0; i < q; i++) {
    cin >> T[i];
  }
  int cnt = 0;
  for (int i = 0; i < q; i++) {
    if (linearSearch(S, T[i])) {
      cnt++;
    }
  }
  cout << cnt << endl;
}