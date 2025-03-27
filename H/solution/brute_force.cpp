#include<bits/stdc++.h>
using namespace std;
const int P = 1e9+7;
const int MAXN = 100;

int add(int a, int b){
    return (a + b) % P;
}

void flip (bitset<MAXN> &coins, int position, const int n, const int k) {
  for (int i = 0; i < k; i++) {
    coins.flip((position + i) % n);
  }
}

int bf(const int n, const int k, int t, bitset<MAXN> &coins) {
  // cerr << ">> " << n << ' ' << k << ' ' << t << ' ' << coins << '\n';
  if (t == 0) return coins.count() == n;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    flip(coins, i, n, k);
    ans = add(ans, bf(n, k, t - 1, coins));
    flip(coins, i, n, k);
  }
  // cerr << "<< " << n << ' ' << k << ' ' << t << ' ' << coins << ' ' << ans << '\n';
  return ans;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, k, t;
  cin >> n >> k >> t;
  if (n == k) {
    cout << t % 2 << '\n';
    return 0;
  }
  if (n > 100) {
    cout << 0 << '\n';
    return 0;
  }
  bitset<MAXN> coins;
  flip(coins, 0, n, k);
  cout << bf(n, k, t-1, coins) << '\n';
  return 0;
}
