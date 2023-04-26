#include<bits/stdc++.h>
using namespace std;

int array_sum_from_i(vector<int> &vec, int i) {
  if (i == vec.size()) return 0;
  return array_sum_from_i(vec, i + 1) + vec.at(i);
}

int array_sum(vector<int> &vec) {
  return array_sum_from_i(vec, 0);
}

int main() {
  vector<int> a = {0, 3, 9, 1, 5};
  cout << array_sum(a) << endl;   // 0 + 3 + 9 + 1 + 5 = 18
}