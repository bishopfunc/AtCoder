#include <bits/stdc++.h>
using namespace std;
#define MAX 2000000

int A[MAX] = {};
int H = 1;

int parent(int i) { return i / 2; }
int left(int i) { return 2 * i; }
int right(int i) { return 2 * i + 1; }

// 最大Heapを作る
void maxHeapify(int i) {
  int l = left(i);
  int r = right(i);
  int largest = i;
  if (r <= H && A[r] > A[largest]) largest = r;
  if (l <= H && A[l] > A[largest]) largest = l;
  if (largest != i) {
    swap(A[i], A[largest]);
    maxHeapify(largest);
  }
}

// 最大要素を取り出して、最大Heapを保つ
int extract() {
  if (H < 1) return -1;  // エラー
  int maxv = A[1];       // 最大値を格納
  A[1] = A[H];           // 最後の要素を根に持ってくる
  H--;                   // ヒープサイズを減らす
  maxHeapify(1);         // 根からヒープを作り直す
  return maxv;
}

// 要素を挿入して、最大Heapを保つ
void insert(int key) {
  H++;         // ヒープサイズを増やす
  A[H] = key;  // 最後尾に挿入
  int i = H;
  // 根までたどり着くか、親の値が大きい場合、まで交換する
  while (i > 1 && A[i / 2] < A[i]) {
    swap(A[i / 2], A[i]);
    i = parent(i);
  }
  // for (int i = H / 2; i >= 1; i--) {
  //   maxHeapify(i);
  // } 
  // これでもいいが無駄が多い
}

int main() {
  string command;
  int key;
  while (true) {
    cin >> command;
    if (command == "insert") {
      cin >> key;
      insert(key);
    } else if (command == "extract") {
      cout << extract() << endl;
    } else if (command == "end") {
      break;
    }
  }
}