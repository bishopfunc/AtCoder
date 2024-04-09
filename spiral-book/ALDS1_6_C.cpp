#include <bits/stdc++.h>
using namespace std;
#define SENTINEL 2000000000

struct Card {
  char suit;
  int value;
};
void merge(vector<Card> &A, int l, int m, int r) {
  int n1 = m - l;
  int n2 = r - m;
  vector<Card> L(n1 + 1), R(n2 + 1);
  for (int i = 0; i < n1; i++) L[i] = A[l + i];
  for (int i = 0; i < n2; i++) R[i] = A[m + i];
  L[n1].value = R[n2].value = SENTINEL;
  int i = 0, j = 0;
  for (int k = l; k < r; k++) {
    if (L[i].value <= R[j].value) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
  }
}

void mergeSort2(vector<Card> &A, int l, int r) {
  if (l + 1 < r) {
    int m = (l + r) / 2;
    mergeSort2(A, l, m);
    mergeSort2(A, m, r);
    merge(A, l, m, r);
  }
}

int partition(vector<Card> &A, int l, int r) {
  int x = A[r].value;
  int i = l - 1;
  for (int j = l; j < r; j++) {
    if (A[j].value <= x) {
      i++;
      swap(A[i], A[j]);
    }
  }
  i++;
  swap(A[i], A[r]);
  return i;
}

void quickSort2(vector<Card> &A, int l, int r) {
  if (l < r) {
    int q = partition(A, l, r);
    quickSort2(A, l, q - 1);
    quickSort2(A, q + 1, r);
  }
}

int main() {
  int n;
  cin >> n;
  int value;
  char suit;
  vector<Card> A(n), B(n);
  for (int i = 0; i < n; i++) {
    cin >> suit >> value;
    A[i].suit = B[i].suit = suit;
    A[i].value = B[i].value = value;
  }
  mergeSort2(A, 0, n);      // leftは先頭、rightは末尾+1
  quickSort2(B, 0, n - 1);  // leftは先頭、rightは末尾
  bool stable = true;
  for (int i = 0; i < n; i++) {
    if (A[i].suit != B[i].suit) {
      stable = false;
      break;
    }
  }
  if (stable)
    cout << "Stable" << endl;
  else
    cout << "Not stable" << endl;
  for (int i = 0; i < n; i++) {
    cout << B[i].suit << " " << B[i].value << endl;  // quickSort2の結果
  }
}