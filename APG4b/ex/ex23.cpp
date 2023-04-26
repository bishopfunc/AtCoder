#include <bits/stdc++.h>
using namespace std;


int main(){
  int N; cin >> N;
  int tmp, max_num, max_count = -1;
  map<int, int> num_count;


  for(int i = 0; i < N; i++) {
    cin >> tmp;
    if(num_count.count(tmp)) num_count[tmp]++;
    else num_count[tmp] = 1;
  }
  
  for (auto x: num_count) {
    if(max_count < x.second) {
      max_num = x.first; 
      max_count = x.second;
    }
  }
  cout << max_num << " " << max_count << endl;
}

  // auto itr = max_element(num_list.begin(), num_list.end());
  // size_t index = distance(num_list.begin(), itr);