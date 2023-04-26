// 3桁連続だった！！！！
// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//   string N;
//   cin >> N;
//   int num[10];
//   for (int k = 0; k < 10; k++) num[k] = 0;
//   vector<int> v(N.size()); //文字列の長さでvectorを宣言

//   for(int i = 0; i < N.size(); i++){
//       v.at(i) = (int)(N[i] - '0'); //ここで文字列のi番目の要素を数値に変換してvectorに突っ込む
//       for (int k = 0; k < 10; k++) if(k == v.at(i)) num[k]++;
//   }
  
//   for (int k = 0; k < 10; k++) {
//     if(num[k] >= 3) {
//       cout << "Yes" << endl;
//       return 0;
//     }
//   }
//   cout << "No" << endl;
// }

#include <bits/stdc++.h>
using namespace std;
int main() {
  string N;  cin >> N;
  if (N[0] == N[1] && N[1] == N[2]) puts("Yes");
  else if (N[1] == N[2] && N[3] == N[2]) puts("Yes");
  else puts("No");
}
