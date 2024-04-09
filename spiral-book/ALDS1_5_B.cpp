#include <bits/stdc++.h>

#include <iomanip>
using namespace std;
#define SENTINEL 1000000000
#define MAX 500000
int cnt = 0;

// [left, mid)と[mid, right)をソート済みの配列として組み合わせる
void merge(vector<long> &A, int left, int mid, int right) {
    int n1 = mid - left;   // size of L
    int n2 = right - mid;  // size of R
    vector<long> L(n1 + 1);
    vector<long> R(n2 + 1);
    for (int i = 0; i < n1; i++) {
        L[i] = A[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = A[mid + i];
    }
    L[n1] = SENTINEL;
    R[n2] = SENTINEL;
    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        cnt++;
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(vector<long> &A, int left, int right) {
    // leftはソート済みの配列の左端 rightは右端+1
    // left + 1 == rightのときは要素数が1つのとき
    // left + 1 < rightのときは要素数が2つ以上のとき
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
    // ソート済みの配列を組み合わせる
}

int main() {
    int n;
    cin >> n;
    vector<long> S(n);
    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }
    mergeSort(S, 0, n);
    for (int i = 0; i < n; i++) {
        if(i) cout << " ";
        cout << S[i];
    }
    cout << endl;
    cout << cnt << endl;
}