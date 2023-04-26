#include <bits/stdc++.h>
using namespace std;

bool sort_first_and_reverse_second(const tuple<string, int, int> &a, const tuple<string, int, int> &b) {
  if (get<0>(a) == get<0>(b)) return (get<1>(a) > get<1>(b));
  return (get<0>(a) < get<0>(b)); 
}

int main() {
  int N; cin >> N;
  string a; int b;
  vector < tuple<string, int, int> > vec(N);
  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    vec.at(i) = make_tuple(a, b, i + 1);
  }
  sort(vec.begin(), vec.end(), sort_first_and_reverse_second);
  for (tuple<string, int, int>  tup: vec) cout << get<2>(tup) << endl;
}