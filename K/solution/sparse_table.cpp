#pragma GCC optimize("Ofast,unroll-loops,O3")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define x first
#define y second
#define N 4000015
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, c, arr[N], st[25][N], l[N], r[N], lg[N];

inline int query(int x, int y){
    if (x > y)
        return 1e9;
    int s = lg[y - x + 1];
    return min(st[s][x], st[s][y - (1 << s) + 1]);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
        cin >> arr[i], st[0][i] = arr[i];
    
    lg[1] = 0, lg[2] = 1;
    for (int i = 3; i <= n; i++)
        lg[i] = lg[i / 2] + 1;
    for (int i = 1; i <= 24; i++)
        for (int j = 1; j <= n; j++){
            if (j + (1 << (i - 1)) <= n)
                st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            else 
                st[i][j] = st[i - 1][j];
        }
    arr[0] = arr[n + 1] = -1;
    stack<int> s;
    s.push(0);
	for (int i = 1; i <= n; i++){
		while (arr[s.top()] >= arr[i]) s.pop();
		l[i] = s.top();
		s.push(i);
	}

    while (!s.empty())
        s.pop();

	s.push(n + 1);
	for (int i = n; i >= 1; i--){
		while (arr[s.top()] >= arr[i]) s.pop();
		r[i] = s.top();
		s.push(i);
	}

    ll ans = c;
    for (int i = 1; i <= n; i++){
        int ql = 1, qr = l[i], usel, user;
        while (ql < qr){
            int mid = (ql + qr) >> 1;
            if (query(mid, l[i] - 1) < arr[i])
                ql = mid + 1;
            else qr = mid;
        }
        usel = ql - 1;
        ql = r[i], qr = n + 1;
        while (ql < qr){
            int mid = (ql + qr) >> 1;
            if (query(r[i] + 1, mid) >= arr[i])
                ql = mid + 1;
            else qr = mid;
        }
        user = ql;
        ll ans1 = (ll)(r[i] - usel - 1) * min(arr[i], c);
        ll ans2 = (ll)(user - l[i] - 1) * min(arr[i], c);
        ll ans3 = (ll)(r[i] - l[i] - 1) * arr[i];
        ans = max({ans, ans1, ans2, ans3});
    }
    cout << ans << '\n';
}