#include <bits/stdc++.h>
using namespace std;

struct MyPair {
  int x;
  string y;
  // 別のMyPair型のオブジェクトをとって、x, yにそれぞれ+したものを返す
  // +演算子をオーバーロード
  MyPair operator+(const MyPair &other) {
    MyPair ret;
    ret.x = x + other.x;  // ここではint型の+演算子が呼ばれる
    ret.y = y + other.y;  // ここではstring型の+演算子が呼ばれる
    return ret;
  }
};

int main() {
  MyPair a = {123, "hello"};
  MyPair d = {1000, " "};
  MyPair b = {456, "world"};

  // MyPair型の+演算子が呼ばれる
  MyPair c = a + d + b;

  cout << "c.x = " << c.x << endl;
  cout << "c.y = " << c.y << endl;
}
