#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int w[MAXN], s[MAXN], t[MAXN], a[MAXN], b[MAXN];
string c[MAXN];
set<pair<int, int>> value;

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  int n = opt<int>(1);
  int w_l = opt<int>(2);
  int w_r = opt<int>(3);
  int a_l = opt<int>(4);
  int a_r = opt<int>(5);
  int b_l = opt<int>(6);
  int b_r = opt<int>(7);
  int name_len = opt<int>(8);
  printf("%d\n", n);
  for (int i = 0; i < n; ++i) {
    w[i] = rnd.next(w_l, w_r); // week
    s[i] = rnd.next(1, 14);    // start
    t[i] = rnd.next(s[i], 14); // end
    do {
      a[i] = rnd.next(a_l, a_r + 1);
      b[i] = rnd.next(b_l, b_r + 1);
    } while (value.count({a[i], b[i]}));
    value.insert({a[i], b[i]});
    c[i] = rnd.next("[A-Za-z]{1, %d}", name_len);
    printf("%d %d %d %d %d %s\n", w[i], s[i], t[i], a[i], b[i], c[i].c_str());
  }
  return 0;
}
