#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------

const int MAX = 100000;
int head = 0, tail = 0;
int qu[MAX]; //stackを表す配列

void init() {
  head = tail = 0;
}

bool isEmpty() {
  return (head == tail); //head = tail = 0以外入ってる
}

bool isFull() {
  return (head == (tail + 1) % MAX); //次入れたら衝突する
}

void enqueue(int v) {
  if (isFull()) {
    cout << "queue is full" << endl;
    return;
  }
  qu[tail++] = v;
  if (tail == MAX) tail = 0; //+してMAXなった瞬間0に行く,tail=N-1+1->0
}


int dequeue() {
  if (isEmpty()) {
    cout << "queue is empty" << endl;
    return -1;
  }
  int res = qu[head++];
  if (head == MAX) head = 0; 
  return res;
}

int main() {
  init();
  rep(i, 0, 10) enqueue(i);
  cout << dequeue() << endl;
  cout << dequeue() << endl;
  cout << dequeue() << endl;
}