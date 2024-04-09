#include <bits/stdc++.h>

#include <stack>
using namespace std;
template <typename Iterable>
void printElements(const Iterable& container);
enum {
    BACKSLASH_SLASH,
    SLASH_BACKSLASH,
    SLASH_UNDERSCORE,
    UNDERSCORE_SLASH,
    BACKSLASH_UNDERSCORE,
    UNDERSCORE_BACKSLASH,
};
map<int, string> m = {
    {BACKSLASH_SLASH, "\\/"},      {SLASH_BACKSLASH, "/\\"},
    {SLASH_UNDERSCORE, "/_"},      {UNDERSCORE_SLASH, "_/"},
    {BACKSLASH_UNDERSCORE, "\\_"}, {UNDERSCORE_BACKSLASH, "_\\"},
};
// \/ 0  /\ 1 \_ 2 _/ 3

int main() {
    vector<string> S;
    vector<tuple<int, int, string>> turnPoints;  // i, elevation, turn
    string s;
    int elevation = 0;
    string trun;
    while (cin >> s) {
        S.push_back(s);
    }
    for (int i = 0; i < (int)S.size(); i++) {
        if (i > 0) {
            trun = S[i - 1] + S[i];
            cout << S[i - 1]  << endl;
            cout << S[i]  << endl;
            if (S[i - 1] == "\\") {
                elevation--;
            } else if (S[i - 1] == "/") {
                elevation++;
            }
            if (trun == m[BACKSLASH_SLASH] || trun == m[SLASH_BACKSLASH] ||
                trun == m[BACKSLASH_UNDERSCORE] ||
                trun == m[UNDERSCORE_SLASH] || trun == m[SLASH_UNDERSCORE] ||
                trun == m[UNDERSCORE_BACKSLASH]) {
                turnPoints.push_back(make_tuple(i, elevation, trun));
            }
        }
    }
    int area = 0;
    for (int i = 0; i < (int)turnPoints.size(); i++) {
        int id = get<0>(turnPoints[i]);
        string turn = get<2>(turnPoints[i]);
        int elevation = get<1>(turnPoints[i]);
        cout << id << " " << turn << " " << elevation << endl;
    }
}

template <typename Iterable>
void printElements(const Iterable& container) {
    for (auto it = begin(container); it != end(container); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}