//Challenge: Accepted
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#ifdef zisk
void debug(){cout << endl;}
template<class T, class ... U> void debug(T a, U ... b){cout << a << " ", debug(b...);}
template<class T> void pary(T l, T r) {
	while (l != r) cout << *l << " ", l++;
	cout << endl;
}
#else
#define debug(...) 0
#define pary(...) 0
#endif
#define ll long long
#define maxn 100005
#define pii pair<ll, ll>
#define ff first
#define ss second
#define io ios_base::sync_with_stdio(0);cin.tie(0);
#define iter(v) v.begin(),v.end()
#define SZ(v) (int)v.size()
#define pb emplace_back
const ll inf = 1LL<<60;
int main() {
	io;
    int n;
    cin >> n;
    vector<pii> v;
    for (int i = 0;i < n;i++) {
        ll ri, si;
        cin >> ri >> si;
        v.push_back({ri, si});
    }
    ll time = 0, ans = 0;
    priority_queue<ll> pq;
    sort(v.begin(), v.end(), [&] (pii a, pii b){return a.second+a.first < b.second+b.first;});
    for (int i = 0;i < n;i++) {
        if (time <= v[i].second) {
            ans += 1;
            time += v[i].first;
            pq.push(v[i].first);
        } else if (v[i].first < pq.top()) {
            time = time - pq.top() + v[i].first;
            pq.pop();
            pq.push(v[i].first);
        }
    }
    cout << ans << endl;
}
