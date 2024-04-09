#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------

void Heapify(vector<int> &a, int i, int N) {
  int child1 = i * 2 + 1;
  if (child1 >= N) return; //範囲超え
  if (child1 + 1 < N && a[child1 + 1] > a[child1]) child1++; //child1 + 1するか、左の子か右か
  if (a[child1] <= a[i]) return; //この方が小さいなら何もしない
  swap(a[i], a[child1]); 
  Heapify(a, child1, N); //再帰的に子も実行する,下に
}

void HeapSort(vector<int> &a) {
  int N = (int)a.size();

  //step1: 全体のヒープを作る
  for (int i = N / 2 - 1; i >= 0; i--) {
    Heapify(a, i, N);
  }
  //step2: 毎回popして、ヒープを作り直す
  for (int i = N - 1; i >= 0; i--) {
    swap(a[0], a[i]); //a[0]はすでにヒープにより最大値
    Heapify(a, 0, i); //ヒープを作る
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
  HeapSort(a);
  printVector(a);
}