#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, A;
  cin >> N >> A;
  int big = (N - (N % 500)) / 500;
  int small = N - 500 * big;
  if (A >= small) cout << "Yes" << endl;
  else cout << "No" << endl;
}