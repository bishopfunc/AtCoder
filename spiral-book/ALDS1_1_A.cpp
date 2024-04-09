#include <bits/stdc++.h>
using namespace std; 

void printArray(int A[], int N);
void insertionSort(int A[], int N);

int main() {
  int N; cin >> N;
  int A[N];
  for (int i = 0; i < N; i++) cin >> A[i];
  insertionSort(A, N);
}

void insertionSort(int A[], int N) {
  int i, j, v;
  for (int i = 0; i < N; i++) {
    v = A[i];
    j = i - 1;
    while(j >= 0 && A[j] > v) {
      A[j + 1] = A[j];
      j--;
    } 
    A[j + 1] = v;
    printArray(A, N);
  }
}

void printArray(int A[], int N) {
  for (int i = 0; i < N; i++) {
    if (i > 0) cout << " ";
    cout << A[i];
  }
  cout << endl;
}

