#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int idx[MAXN];
int w[MAXN], s[MAXN], t[MAXN], a[MAXN], b[MAXN];
string c[MAXN];
bool schedule[10][16];
set<string> names;
void dnq(int l, int r) {
  if (l == r)
    return;
  int mid = (l + r) >> 1;
  dnq(l, mid);
  dnq(mid + 1, r);
  vector<int> tmp;
  int l_ptr = l, r_ptr = mid + 1;
  while (l_ptr <= mid && r_ptr <= r) {
    if (a[idx[l_ptr]] == a[idx[r_ptr]]) {
      if (b[idx[l_ptr]] > b[idx[r_ptr]])
        tmp.push_back(idx[l_ptr++]);
      else
        tmp.push_back(idx[r_ptr++]);
    } else {
      if (a[idx[l_ptr]] > a[idx[r_ptr]])
        tmp.push_back(idx[l_ptr++]);
      else
        tmp.push_back(idx[r_ptr++]);
    }
  }
  while (l_ptr <= mid)
    tmp.push_back(idx[l_ptr++]);
  while (r_ptr <= r)
    tmp.push_back(idx[r_ptr++]);
  for (int i = l; i <= r; ++i) {
    idx[i] = tmp[i - l];
  }
  return;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> w[i] >> s[i] >> t[i] >> a[i] >> b[i] >> c[i];
  }
  iota(idx, idx + n, 0);
  dnq(0, n - 1);
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
