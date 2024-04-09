#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------

const int MAX = 100000;
int top = 0;
int st[MAX]; //stackを表す配列

void init() {
  top = 0;
}

bool isEmpty() {
  return (top == 0);
}

bool isFull() {
  return (top == MAX);
}

void push(int v) {
  if (isFull()) {
    cout << "stack is full" << endl;
    return;
  }
  st[++top] = v;
}


int pop() {
  if (isEmpty()) {
    cout << "stack is empty" << endl;
    return -1;
  }
  return st[top--];
}

int main() {
  init();
  rep(i, 0, 10) push(i);
  cout << pop() << endl;
  cout << pop() << endl;
  cout << pop() << endl;
}