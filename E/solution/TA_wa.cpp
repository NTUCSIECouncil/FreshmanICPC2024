#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
  int n;
  cin >> n;
  vector<pair<int, int>> tasks(n);
  for (auto &i : tasks) {
    cin >> i.second >> i.first;
  }
  sort(tasks.begin(), tasks.end());
  int cur_time = 0;
  priority_queue<int> pq;
  for (auto &x : tasks) {
    if (x.first >= cur_time) {
      pq.push(x.second);
      cur_time += x.second;
    } else if (x.second < pq.top()) {
      cur_time += x.second - pq.top();
      pq.pop();
      pq.push(x.second);
    }
  }
  int ans = 0;
  while (!pq.empty()) {
    pq.pop();
    ans++;
  }
  cout << ans << endl;
}
