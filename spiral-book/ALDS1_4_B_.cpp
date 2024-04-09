#include <bits/stdc++.h>

#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<int> S(n);
    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }
    cin >> q;
    vector<int> T(q);
    for (int i = 0; i < q; i++) {
        cin >> T[i];
    }
    int cnt = 0;
    // keyより大きい最初の要素のイテレータがkeyと等しいかどうか
    for (int i = 0; i < q; i++) {
        if (*lower_bound(S.begin(), S.end(), T[i]) == T[i]) {
            cnt++;
        }
    }
    cout << cnt << endl;
}