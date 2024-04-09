 #include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> bits;
  for (int i = 9; i >= 0; i--) {
    int dividend = 1 << i;
    cout << (N / dividend % 2);
  }
  cout << endl;
}
// 13 / 8 = 1 -> 1
// 13 / 4 = 3 -> 1
// 13 / 2 = 8 -> 0
// 13 / 1 = 13 -> 1
// 13 = 8 + 4 + 1
// N / (2^n)が偶数なら、単体で存在しない、2*2=4みたいに