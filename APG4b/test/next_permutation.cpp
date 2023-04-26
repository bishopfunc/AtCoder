#include <bits/stdc++.h>
using namespace std;

void print(vector<int> v) {
    for (int x : v) {
      cout << x << " ";
    }
    cout << endl;
}


int main() {
  vector<int> v = { 2, 1, 3 };
  sort(v.begin(), v.end());
  do {
    // 今の並び方はnext_permutation出力で出力できないから
   print(v);
  } while (next_permutation(v.begin(), v.end()));
}
