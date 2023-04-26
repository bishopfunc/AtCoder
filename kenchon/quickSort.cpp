#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define rep2(i, s, n) for (int i = (s); i >= (int)(n); i--) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------

void QuickSort(vector<int> &a, int l, int r) {
  if (r - l <= 1) return; //隣ならreturn
  int pivot_i = (l + r) / 2;
  int pivot = a[pivot_i];
  swap(a[pivot_i], a[r - 1]); //右端にpivotを置く
  int i = l;
  rep(j, l, r - 1) {
    if (a[j] < pivot) swap(a[i++], a[j]); //iはpivotより小さい、1個動かす
  }
  swap(a[i], a[r - 1]); //pivotを戻す

  QuickSort(a, l, i); //pivot未満
  QuickSort(a, i + 1, r); //pivot以上 pivotはスキップ

}

void printVector(vector<int> &a) {
  rep(i, 0, (int)a.size()) {
    cout << a[i] << " ";
  }
  cout << endl;
}

int main() {
  int N; cin >> N;
  vector<int> a(N);
  rep(i, 0, N) cin >> a[i];
  
  printVector(a);
  QuickSort(a, 0, N);
  printVector(a);
}