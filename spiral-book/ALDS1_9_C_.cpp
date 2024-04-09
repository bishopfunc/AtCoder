#include <bits/stdc++.h>
using namespace std;

int main() {
  string command;
  int key;
  priority_queue<int> pq;
  while (true) {
    cin >> command;
    if (command == "insert") {
      cin >> key;
      pq.push(key);
    } else if (command == "extract") {
      cout << pq.top() << endl;
      pq.pop();
    } else if (command == "end") {
      break;
    }
  }
}