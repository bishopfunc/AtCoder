#include <bits/stdc++.h>
using namespace std;
 
 int main() {
  u_int32_t *p;
  p = new u_int32_t[10];
  u_int32_t *tmp = p;
  for (int i = 0; i < 10; i++) {
    *tmp = i;
    tmp++;
  }
  tmp = p;
  for (int i = 0; i < 10; i++) {
    cout << *tmp << endl;
    tmp++;
  }
  
 }