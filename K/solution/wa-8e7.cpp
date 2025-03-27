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
#define pii pair<int, int>
#define ff first
#define ss second
#define io ios_base::sync_with_stdio(0);cin.tie(0);
#define iter(v) v.begin(),v.end()
#define SZ(v) (int)v.size()
#define pb emplace_back
int n, c;
void solve(ll &ans, vector<int> &a) {
    vector<int> lb(n);
    vector<int> help;
    vector<int> stk;
    for (int i = 0;i < n;i++) {
        while (help.size() && a[i] < a[help.back()]) {
            ans = max(ans, (ll)(i - lb[help.back()]) * a[help.back()]);
            help.pop_back();
        }
        vector<int> add_to_help;
        while (stk.size() && a[i] < a[stk.back()]) {
            ans = max(ans, (ll)(i - lb[stk.back()]) * a[stk.back()]);
            if (a[stk.back()] < c) {
                add_to_help.push_back(stk.back()); 
            }
            stk.pop_back();
        }
        while (add_to_help.size()) {
            help.push_back(add_to_help.back());
            add_to_help.pop_back();
        }
        if (stk.size() == 0) lb[i] = 0;
        else lb[i] = stk.back()+1;
        stk.push_back(i);
    }
    while (help.size()) {
        ans = max(ans, (ll)(n - lb[help.back()]) * a[help.back()]);
        help.pop_back();
    }
    while (stk.size()) {
        ans = max(ans, (ll)(n - lb[stk.back()]) * a[stk.back()]);
        stk.pop_back();
    }
}
int main() {
	io;
    cin >> n >> c;
    vector<int> a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    ll ans = 0;
    solve(ans, a);
    reverse(a.begin(), a.end());
    solve(ans, a);
    cout << ans << "\n";
}
