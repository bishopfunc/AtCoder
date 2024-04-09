#include <bits/stdc++.h>
using namespace std;
#define MAX_N 500001
int A[MAX_N] = {};
int H;

int parent(int i) { return i / 2; }
int left(int i) { return 2 * i; }
int right(int i) { return 2 * i + 1; }

void maxHeapify(int i) {
  int l = left(i);
  int r = right(i);
  // cout << "i: " << i << " l: " << l << " r: " << r << endl;
  int largest = i;
  if (l <= H && A[l] > A[i]) {  // 範囲外なら比較しない
    largest = l;
  }
  if (r <= H && A[r] > A[largest]) {
    largest = r;
  }
  // 範囲外なら比較しない  max(abc)だと個別にできない
  if (largest != i) {
    swap(A[i], A[largest]);
    maxHeapify(largest);
  }
}

int main() {
  cin >> H;
  for (int i = 1; i <= H; i++) {
    cin >> A[i];
  }
  // H/2 * 2 = Hが葉ノードはやる必要がない
  // 1から始めても再帰でいかないところがある
  for (int i = H / 2; i >= 1; i--) {
    maxHeapify(i);
  }
  for (int i = 1; i <= H; i++) {
    if (i != H + 1) cout << " ";
    cout << A[i];  // 1-indexed
  }
  cout << endl;
}