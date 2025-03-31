#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int idx[MAXN];
int w[MAXN], s[MAXN], t[MAXN], a[MAXN], b[MAXN];
string c[MAXN];
bool schedule[10][16];
set<string> names;
bool cmp(int x, int y) {
  if (a[x] == a[y])
    return b[x] > b[y];
  return a[x] > a[y];
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> w[i] >> s[i] >> t[i] >> a[i] >> b[i] >> c[i];
  }
  iota(idx, idx + n, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      if (cmp(idx[i], idx[j])) {
        swap(idx[i], idx[j]);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    int x = idx[i];
    if (names.count(c[x])) {
      continue;
    }
    bool flag = true;
    for (int j = s[x]; j <= t[x]; ++j) {
      if (schedule[w[x]][j]) {
        flag = false;
        break;
      }
    }
    if (!flag)
      continue;
    for (int j = s[x]; j <= t[x]; ++j) {
      schedule[w[x]][j] = true;
    }
    names.insert(c[x]);
  }
  int cnt = 0;
  for (int i = 1; i <= 7; ++i) {
    for (int j = 1; j <= 15; ++j) {
      cnt += schedule[i][j];
    }
  }
  cout << cnt << '\n';
}
