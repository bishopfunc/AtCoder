#include <bits/stdc++.h>

using namespace std; 


int main() {
  vector<string> S;
  string s;
  while (cin >> s) {
    S.push_back(s);
  }
  stack<int> stack;
  int a, b;
  for (int i = 0; i < (int)S.size(); i++) {
    if (S[i] == "+") {
      b = stack.top(); stack.pop();
      a = stack.top(); stack.pop();
      stack.push(a + b);
    }
    else if (S[i] == "-") {
      b = stack.top(); stack.pop();
      a = stack.top(); stack.pop();
      stack.push(a - b);
    }
    else if (S[i] == "*") {
      b = stack.top(); stack.pop();
      a = stack.top(); stack.pop();
      stack.push(a * b);
    }    
    else {
      stack.push(stoi(S[i].c_str()));
    }
  }
  cout << stack.top() << endl;
}
