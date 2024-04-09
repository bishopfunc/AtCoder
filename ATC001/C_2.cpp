// 参考
// https://qiita.com/ageprocpp/items/0d63d4ed80de4a35fe79
// https://trap.jp/post/1386/
// https://atcoder.jp/contests/atc001/tasks/fft_c
// https://qiita.com/ngtkana/items/a41344ad3304d2315c46
// https://www.youtube.com/watch?v=GseqjWgmw6Q&t=284s

#include <bits/stdc++.h>

#include <complex>
using namespace std;

class FFT {
 public:
  FFT() {}
  void DFT(vector<complex<double>>& A, bool inverse = false) {
    int N = A.size();
    if (N == 1) return;
    vector<complex<double>> even(N / 2), odd(N / 2);
    for (int i = 0; i < N / 2; i++) {
      even[i] = A[i * 2];
      odd[i] = A[i * 2 + 1];
    }
    DFT(even, inverse);
    DFT(odd, inverse);
    double theta = (inverse ? -1 : +1) * 2 * M_PI / N;
    complex<double> W(1), Wn(cos(theta), sin(theta));
    // 回転因子の初期値(1,0)と1回転(1,θ)
    for (int i = 0; i < N / 2; i++) {
      A[i] = even[i] + W * odd[i];
      A[i + N / 2] = even[i] - W * odd[i];
      W *= Wn;
    }
  }
  vector<complex<double>> IDFT(vector<complex<double>>& A) {
    DFT(A, true);
    int N = A.size();
    for (auto& a : A) a /= N;  // サイズで割る
    return A;
  }
  vector<complex<double>> convolution(vector<complex<double>>& A,
                                      vector<complex<double>>& B) {
    int N = 1;
    while (N < (int)(A.size() + B.size())) N *= 2;
    vector<complex<double>> FA(A.begin(), A.end()), FB(B.begin(), B.end());
    FA.resize(N);
    FB.resize(N);
    DFT(FA);
    DFT(FB);
    vector<complex<double>> FC(N);
    for (int i = 0; i < N; i++) FC[i] = FA[i] * FB[i];
    FC = IDFT(FC);
    FC.resize(A.size() + B.size() - 1);
    return FC;
  }
};
int main() {
  int N;
  cin >> N;
  vector<int> A(N + 1), B(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> A.at(i) >> B.at(i);
  }
  vector<complex<double>> complex_A(A.begin(), A.end()),
      complex_B(B.begin(), B.end());
  FFT fft;
  vector<complex<double>> complex_C = fft.convolution(complex_A, complex_B);
  for (int i = 1; i <= 2 * N; i++) {
    cout << (int)round(complex_C[i].real()) << endl;
  }
}