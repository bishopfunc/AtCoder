#include<bits/stdc++.h>
using namespace std;

vector<int> reverse_array_from_i(vector<int> &vec, int i) {
  if(i == vec.size()){
    vector<int> empty_array;
    return empty_array;
  } 
  vector<int> tmp = reverse_array_from_i(vec, i + 1);
  tmp.push_back(vec.at(i));
  return tmp;
}

vector<int> reverse_array(vector<int> &vec) {
  return reverse_array_from_i(vec, 0);
}

int main() {
  vector<int> a = {1, 2, 3, 4, 5};
  vector<int> b = reverse_array(a);
  for (int i = 0; i < b.size(); i++) {
    cout << b.at(i) << endl;
  }
}