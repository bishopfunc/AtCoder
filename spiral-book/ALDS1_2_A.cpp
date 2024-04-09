#include <bits/stdc++.h>
using namespace std; 

void printArray(int A[], int N);
int bubbleSort(int A[], int N);
void swap(int *a, int *b);

int main() {
  int N; cin >> N;
  int A[N];
  for (int i = 0; i < N; i++) cin >> A[i];
  int c = bubbleSort(A, N);
  printArray(A, N);
  cout << c << endl;
}

int bubbleSort(int A[], int N) {
  int i, j, c;
  bool flag = true;
  i = 0; c = 0;
  while (flag) {
    flag = false;
    for (int j = N - 1; j >= i + 1; j--) {
      if(A[j - 1] > A[j]) {
        swap(&A[j - 1], &A[j]);
        flag = true;
        c++;
      }
    }
    i++;
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

