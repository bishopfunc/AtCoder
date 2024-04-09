#include <bits/stdc++.h>
using namespace std;
#define M 1046527

int h1(int key) { return key % M; }

int h2(int key) { return 1 + (key % (M - 1)); }

int h(int key, int i) { return (h1(key) + i * h2(key)) % M; }

int insert(vector<int> &array, int key) {
    int i = 0;
    while (true) {
        int j = h(key, i);
        if (array[j] == 0) {
            array[j] = key;
            return j;
        } else
            i++;
    }
}

int search(vector<int> &array, int key) {
    int i = 0;
    while (true) {
        int j = h(key, i);
        if (array[j] == key) {
            return j;
        } else if (array[j] == 0 || i >= M) {
            return -1;
        } else
            i++;
    }
}

int keyToInt(string key) {
    int sum = 0;
    int p = 1;
    reverse(key.begin(), key.end());
    for (int i = 0; i < key.size(); i++) {
        int x = 0;
        if (key[i] == 'A') {
            x = 1;
        } else if (key[i] == 'C') {
            x = 2;
        } else if (key[i] == 'G') {
            x = 3;
        } else if (key[i] == 'T') {
            x = 4;
        }
        sum += p * x;
        p *= 5;
    }
    // 5^12 = 244140625
    // INT32_MAX = 244140625;
    // 10^12ならlong long
    return sum;
}

int main() {
    int n;
    string command, key;
    int keyi;
    vector<int> array(M);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> command >> key;
        keyi = keyToInt(key);
        // cout << keyi << endl;
        if (command == "insert") {
            insert(array, keyi);
        } else if (command == "find") {
            if (search(array, keyi) != -1) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }
    }
}