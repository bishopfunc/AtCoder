#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define rep2(i, s, n) for (int i = (s); i >= (int)(n); i--) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------

void MergeSort(vector<int> &a, int l, int r) {
  if (r - l == 1) return; //隣ならreturn
  int m = l + (r - l) / 2;
  MergeSort(a, l, m);
  MergeSort(a, m, r);

  vector<int> buf;
  rep(i, l, m) buf.push_back(a[i]);
  rep2(i, r - 1, m) buf.push_back(a[i]); //MergeSort(a, 0, N) 
  // 逆向きに入れる

  int index_l = 0;
  int index_r = (int)buf.size() - 1;

  // 再帰の範囲内でiをループ
  rep(i, l, r) {
    if (buf[index_l] < buf[index_r]) {
      a[i] = buf[index_l++]; //代入したら次へ
    }
    else{
      a[i] = buf[index_r--]; //代入したら次へ
    }
  } 
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
  MergeSort(a, 0, N);
  printVector(a);
}