#include <bits/stdc++.h>
using namespace std;
 
int main() {
  vector<int> data(5);
  int tmp = -1;
  for (int i = 0; i < 5; i++) {
    cin >> data.at(i);
  }
 

  for(int a: data) {
    if(tmp == a) {
      cout << "YES" << endl; 
      return 0;
    }
    tmp = a;
  }
  cout << "NO" << endl;
}