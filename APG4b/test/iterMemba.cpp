#include <bits/stdc++.h>
using namespace std;
 
int main() {
  vector<pair <int, int> > a = {{1, 4}, {2, 5}, {3, 6}};
  auto itr = a.begin() + 1;
  // cout << (*itr).first << ", " << (*itr).second << endl; と書くのと同じ
  cout << (itr->first) << ", " << (itr->second) << endl;
}