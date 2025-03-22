#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
const int MAXVAL = 1e9;
const int S = 1;
const int T = 14;
long long int w[MAXN], s[MAXN], t[MAXN], a[MAXN], b[MAXN];
string c[MAXN];
set<pair<int, int>> value;

int main() {
  registerValidation();
  int n = inf.readInt(1, MAXN, "n");
  inf.readEoln();
  fprintf(stderr, "n = %d\n", n);
  for (int i = 0; i < n; ++i) {
    w[i] = inf.readInt(1, 7, "w_i");
    inf.readSpace();
    s[i] = inf.readInt(S, T, "s_i");
    inf.readSpace();
    t[i] = inf.readInt(S, T, "t_i");
    inf.readSpace();
    a[i] = inf.readInt(-MAXVAL, MAXVAL, "a_i");
    inf.readSpace();
    b[i] = inf.readInt(-MAXVAL, MAXVAL, "b_i");
    ensure(!value.count({a[i], b[i]}));
    value.insert({a[i], b[i]});
    inf.readSpace();
    c[i] = inf.readWord("[A-Za-z]{1, 10}", "c_i");
    inf.readEoln();
  }
  inf.readEof();
  return 0;
}
