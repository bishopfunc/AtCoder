#include <bits/stdc++.h>
using namespace std;

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}

int main() {
  int N; cin >> N;
  int a, b;
  vector < pair<int, int> > vec;
  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    vec.push_back(make_pair(a, b));
  }
  sort(vec.begin(), vec.end(), sortbysec);
  for (pair<int, int> p: vec) cout << p.first << " " << p.second << endl;

}