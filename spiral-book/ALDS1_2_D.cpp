#include <bits/stdc++.h>
using namespace std; 

template <typename Iterable> void printElements(const Iterable& container);
template <typename Iterable> void printElementsBack(const Iterable& container);
void printArray2(int A[], int N);
int insertionSort(int A[], int N, int g);
int shellSort(int A[], int N, vector<int> &G, int m);
vector<int> generateG(int N);

int main() {
  
  int N, M; cin >> N;
  int A[N];
  vector<int> G;
  for (int i = 0; i < N; i++) cin >> A[i];
  G = generateG(N);
  int m = (int)G.size();
  int c = shellSort(A, N, G, m);
  cout << m << endl;
  printElementsBack(G);
  cout << c << endl;
  printArray2(A, N);
}

vector<int> generateG(int N) {
  int h = 1;
  vector<int>G;
  while (true) {
    if(h > N) break;
    G.push_back(h);
    h = 3 * h + 1;
  } 
  return G;
}

// 参照渡し
int shellSort(int A[], int N, vector<int>& G, int m) {
  int c = 0;
  for (int i = m - 1; i >= 0; i--) {
    c += insertionSort(A, N, G[i]);
  }
  return c;
}

int insertionSort(int A[], int N, int g) {
  int i, j, v, c;
  c = 0;
  for (int i = g; i < N; i++) {
    v = A[i];
    j = i - g;
    while(j >= 0 && A[j] > v) {
      A[j + g] = A[j];
      j -= g;
      c++;
    } 
    A[j + g] = v;
  }
  return c;
}

template <typename Iterable>
void printElements(const Iterable& container) {
    for (auto it = std::begin(container); it != std::end(container); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
template <typename Iterable>
void printElementsBack(const Iterable& container) {
    for (auto it = container.rbegin(); it != container.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}


void printArray2(int A[], int N) {
  for (int i = 0; i < N; i++) {
    cout << A[i] << endl;
  }
}

