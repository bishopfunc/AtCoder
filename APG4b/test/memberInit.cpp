#include <bits/stdc++.h>
using namespace std;

struct MyPair {
  int x;
  string y;
  // 初期化子リストを用いた初期化
  MyPair() : x(123), y("hello") {
    // x = 100;
    // y = "hi";
  } 
  MyPair(int x_, string y_) : x(123), y("hello") {
    // x = x_;
    // y = y_;
  } 
};

int main() {
  MyPair p;  // コンストラクタにより初期化される
  cout << "p.x = " << p.x << endl;
  cout << "p.y = " << p.y << endl;
  MyPair q(1000, "world");  // コンストラクタにより初期化される
  cout << "q.x = " << q.x << endl;
  cout << "q.y = " << q.y << endl;
}
