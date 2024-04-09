#include <bits/stdc++.h>
using namespace std; 

void printArray(int A[], int N);
int selectionSort(int A[], int N);
void swap(int *a, int *b);

int main() {
  int N; cin >> N;
  int A[N];
  for (int i = 0; i < N; i++) cin >> A[i];
  int c = selectionSort(A, N);
  printArray(A, N);
  cout << c << endl;
}

int selectionSort(int A[], int N) {
  int i, j, minj, c;
  c = 0;
  for (int i = 0; i < N; i++) {
    minj = i;
    for (int j = i; j < N; j++) {
      if(A[j] < A[minj]) minj = j;
    }
    if (i != minj) {
      swap(&A[i], &A[minj]);
      c++;
    }
  }
  return c;
}

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void printArray(int A[], int N) {
  for (int i = 0; i < N; i++) {
    if (i > 0) cout << " ";
    cout << A[i];
  }
  cout << endl;
}

