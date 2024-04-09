#include <bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int> array, int key) {
  int n = array.size();
  int left = 0;
  int right = n;
  while (left < right) {
    int mid = (left + right) / 2;
    if (array[mid] == key) {return true;}
    else if (array[mid] < key) {left = mid + 1;}
    else if (array[mid] > key) {right = mid;}
  }
  return false;
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
    if (binarySearch(S, T[i])) {
      cnt++;
    }
  }
  cout << cnt << endl;
}