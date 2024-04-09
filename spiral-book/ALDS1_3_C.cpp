#include <bits/stdc++.h>

#include <list>
using namespace std;
template <typename Iterable> void printElements(const Iterable& container);

int main() {
    int N;
    cin >> N;
    int x;
    string command;
    list<int> L;
    for (int i = 0; i < N; i++) {
        cin >> command;
        if (command == "insert") {
            cin >> x;
            L.push_front(x);
        } else if (command == "delete") {
            cin >> x;
            for (list<int>::iterator it = L.begin(); it != L.end(); it++) {
              if (*it == x) {
                L.erase(it);
                break;
              }
            }
        } else if (command == "deleteFirst") {
            L.pop_front();
        } else if (command == "deleteLast") {
            L.pop_back();
        }
        // printElements(L);
    }
    for (list<int>::iterator it = L.begin(); it != L.end(); it++) {
        if (it != L.begin()) cout << " ";
        cout << *it;
    }
    cout << endl;
}

template <typename Iterable>
void printElements(const Iterable& container) {
    for (auto it = begin(container); it != end(container); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}