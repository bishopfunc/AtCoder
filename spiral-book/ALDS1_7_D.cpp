#include <bits/stdc++.h>
using namespace std;

vector<int> preorderArray, inorderArray, postorderArray;
int pos = 0;
void reconstruct(int left, int right) {
  if (left >= right) return;
  int root = preorderArray[pos++];  // preorderのからrootを取得
  auto itr = find(inorderArray.begin(), inorderArray.end(), root);
  int mid = distance(inorderArray.begin(), itr);
  reconstruct(left, mid);          // 左部分木
  reconstruct(mid + 1, right);     // 右部分木
  postorderArray.push_back(root);  // 後行順は左右→根
}

int main() {
  int n, u;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> u;
    preorderArray.push_back(u);
  }
  for (int i = 0; i < n; i++) {
    cin >> u;
    inorderArray.push_back(u);
  }
  reconstruct(0, n);
  for (int i = 0; i < n; i++) {
    if (i) cout << " ";
    cout << postorderArray[i];
  }
  cout << endl;
}
