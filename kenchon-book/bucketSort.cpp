#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define rep2(i, s, n) for (int i = (s); i >= (int)(n); i--) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------

const int MAX = 100000;

void BucketSort(vector<int> &a) {
  int N = (int)a.size();

  vector<int> num(MAX, 0);
  rep(i, 0, N) num[a[i]]++;
  
  // cout << "num: " << endl;
  // rep(i, 0, N) cout << num[i] << " ";
  // cout << endl;

  vector<int> sum(MAX, 0);
  sum[0] = num[0];
  rep(v, 1, MAX) sum[v] = sum[v - 1] + num[v];
  
  // cout << "sum: " << endl;
  // rep(i, 0, N) cout << sum[i] << " ";
  // cout << endl;

  vector<int> a2(N);
  rep2(i, N - 1, 0) a2[--sum[a[i]]] = a[i]; //ここがよくわからん //ここの順番--してから配列をアクセス //被ってたら-1
  a = a2;
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
  BucketSort(a);
  printVector(a);
}