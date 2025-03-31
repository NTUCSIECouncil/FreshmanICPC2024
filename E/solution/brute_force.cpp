#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> pii;

int do_tasks(const vector<pii> &task) {
  int cur_time = 0;
  int num_complete = 0;
  for (auto [p, l] : task) {
    if (l < cur_time) {
      continue;
    }
    num_complete++;
    cur_time += p;
  }
  return num_complete;
}

signed main() {
  int n;
  cin >> n;
  vector<pii> task;
  for (int i = 0; i < n; i++) {
    int p, l;
    cin >> p >> l;
    task.push_back({p, l});
  }
  int max_complete = 0;
  sort(task.begin(), task.end());
  do {
    int task_complete = do_tasks(task);
    max_complete = max(max_complete, task_complete);
    // for (auto [p, l] : task) {
    //   cerr << p << '/' << l << " ";
    // }
    // cerr << '\n';
    // cerr << "complete: " << task_complete << '\n';
  } while (next_permutation(task.begin(), task.end()));
  cout << max_complete << '\n';
  return 0;
}
