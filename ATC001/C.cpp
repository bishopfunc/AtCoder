#include <bits/stdc++.h>
#include<complex>

using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------

vector<complex<double>> fft(vector<complex<double>> a, bool reverse = false) {
  int n = a.size();
  if (n == 1) return a;
  vector<complex<double>> b(n / 2), c(n / 2);
  rep(i, 0, n) {
    if (i % 2 == 0) b[i / 2] = a[i];
    else if (i % 2 == 1) c[i / 2] = a[i];
  }
  b = fft(b, reverse); 
  c = fft(c, reverse);
  double circle = (reverse ? -1 : +1 ) * 2 * M_PI;
  rep(i, 0, n) a[i] = b[i % (n / 2)] + c[i % (n / 2)] * exp(complex<double> (0, circle * i / n));
  return a;
}

int pow_2_at_least(int x) {
  int n = 1;
  while(n < x) n *= 2;
  return n;
}


vector<double> convolution(vector<complex<double>> g, vector<complex<double>> h) {
  int s = g.size() + h.size() - 1;
  int t = pow_2_at_least(s);

  g.resize(t); h.resize(t);
  g = fft(g); h = fft(h);
  vector<complex<double>> f(t);
  rep(i, 0, t) f[i] = g[i] * h[i];
  fft(f, true);

  vector<double> res(s);
  rep(i, 0, s) res[i] = f[i].real() / t; //なぜ
  return res;
}

int main() {
  int N; cin >> N;
  vector<complex<double>> A(N), B(N);
  rep(i, 0, N) cin >> A[i] >> B[i];
  vector<double> C = convolution(A, B);
  rep(k, 0, 2 * N) {
    cout << (int)(C[k] + 0.5) << endl; //??
  }
}