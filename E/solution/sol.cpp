#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> pll;

int main() {
  int n;
  cin >> n;
  vector<pll> task;
  for (int i = 0; i < n; i++) {
    long long p, l;
    cin >> p >> l;
    task.push_back({l, p});
  }
  sort(task.begin(), task.end());
  long long cur_time = 0;
  priority_queue<long long> pq;
  for (auto [l, p] : task) {
    if (l >= cur_time) {
      pq.push(p);
      cur_time += p;
    } else if (p < pq.top()) {
      cur_time += p - pq.top();
      pq.pop();
      pq.push(p);
    }
  }
  cout << pq.size() << '\n';
  return 0;
}
