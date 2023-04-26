#include <bits/stdc++.h>
using namespace std;
int main(){
  string num;
  int count = 0;
  cin >> num;
  for (int i = 0; i < num.size(); i++)
  {
    if(num[i] == '1') count++;
  }
  cout << count << endl;
}