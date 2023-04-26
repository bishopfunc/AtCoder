#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A;
  cin >> N >> A;
  string op;
  bool flag = false;
  int error_idx = N;
  int B;
  vector<int> res;
  for (int i = 0; i < N; i++) {
    cin >> op >> B;
    if(op == "+") {
        res.push_back(A + B);
        A += B;
    }
    else if(op == "-") {
        res.push_back(A - B);
        A -= B;
    }
    else if(op == "*") {
        res.push_back(A * B);
        A *= B;    
    }
    else if(op == "/") {
      if (B == 0) {
        flag = true;
        error_idx = i;
        break;   
      }
      res.push_back(A / B);
      A /= B;
    }
    else {
      flag = true;
      error_idx = i;
      break;
    }
  }
  for (int i = 0; i < error_idx; i++) {
    cout << i + 1 << ":"<< res.at(i) << endl;
  }
  if(flag) cout << "error" << endl;

}
