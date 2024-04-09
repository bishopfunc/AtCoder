#include <bits/stdc++.h>
using namespace std;

// 図の|の左がi
int partition(vector<int> &A, int p, int r) {
    int x = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        // 小さいなら、iが移動し、A[i]とA[j]を交換し、jが移動する
        // <X エリアに移動させる
        if (A[j] <= x) {
            i++;
            swap(A[i], A[j]);
        }
        // 大きいなら、jが移動する
    }
    // ループが終わったら、i+1(|の右)とr(末尾)を交換する
    swap(A[i + 1], A[r]);  // i++とswap(A[i], A[j])と同じ、i+1を返す
    return i + 1;
//     swap(A[++i], A[r]); //同じ
//     return i;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int q = partition(A, 0, n - 1);
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        if (i == q)
            cout << "[" << A[i] << "]";
        else
            cout << A[i];
    }
    cout << endl;
}
