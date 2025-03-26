#pragma GCC optimize("Ofast,unroll-loops,O3")
// #pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define x first
#define y second
#define N 4000015
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline char readchar() {
	const int S = 1<<20; // buffer size
	static char buf[S], *p = buf, *q = buf;
	if(p == q && (q = (p=buf)+fread(buf,1,S,stdin)) == buf) return EOF;
	return *p++;
}

inline int nextint() {
	int x = 0, c = readchar(), neg = false;
	while(('0' > c || c > '9') && c!='-' && c!=EOF) c = readchar();
	if(c == '-') neg = true, c = readchar();
	while('0' <= c && c <= '9') x = x*10 + (c^'0'), c = readchar();
	if(neg) x = -x;
	return x;
}

int n, c, arr[N], seg[2 * N], sl[N], sr[N], lg[N];

// void build(int l, int r, int i){
//     if (l == r){
//         seg[i] = arr[l];
//         return;
//     }
//     int mid = (l + r) >> 1;
//     build(l, mid, i << 1);
//     build(mid + 1, r, i << 1 | 1);
//     seg[i] = min(seg[i << 1], seg[i << 1 | 1]);
// }

// int query(int l, int r, int i, int ql, int qr){
//     if (ql > qr)
//         return 1e9;
//     if (ql <= l && qr >= r)
//         return seg[i];
//     int mid = (l + r) >> 1;
//     if (qr <= mid) return query(l, mid, i << 1, ql, qr);
//     else if (ql > mid) return query(mid + 1, r, i << 1 | 1, ql, qr);
//     else return min(query(l, mid, i << 1, ql, qr), query(mid + 1, r, i << 1 | 1, ql, qr));
// }


inline void init(int n){
    for (int i = 1; i <= n; i++)
        seg[i + n - 1] = arr[i];

    for(int i = n - 1; i >= 1; i--)
        seg[i] = min(seg[i << 1], seg[i << 1 | 1]);
}

inline int query(int l, int r){
    if (l > r)
        return 1e9;
    int res = 1e9;
    for (l += n - 1, r += n - 1; l <= r; l >>= 1, r >>= 1){
        if (l & 1) res = min(res, seg[l++]);
        if (r & 1 ^ 1) res = min(res, seg[r--]);
    }
    return res;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cin >> n >> c;
    n = nextint(), c = nextint();
    for (int i = 1; i <= n; i++)
        arr[i] = nextint();
        // cin >> arr[i];
    
    // build(1, n, 1);
    init(n);
    arr[0] = arr[n + 1] = -1;
    stack<int> s;
    s.push(0);
	for (int i = 1; i <= n; i++){
		while (arr[s.top()] >= arr[i]) s.pop();
		sl[i] = s.top();
		s.push(i);
	}

    while (!s.empty())
        s.pop();

	s.push(n + 1);
	for (int i = n; i >= 1; i--){
		while (arr[s.top()] >= arr[i]) s.pop();
		sr[i] = s.top();
		s.push(i);
	}

    ll ans = c;
    for (int i = 1; i <= n; i++){
        int ql = 1, qr = sl[i], usel, user;
        while (ql < qr){
            int mid = (ql + qr) >> 1;
            // if (query(1, n, 1, mid, sl[i] - 1) < arr[i])
            if (query(mid, sl[i] - 1) < arr[i])
                ql = mid + 1;
            else qr = mid;
        }
        usel = ql - 1;
        ql = sr[i], qr = n + 1;
        while (ql < qr){
            int mid = (ql + qr) >> 1;
            // if (query(1, n, 1, sr[i] + 1, mid) >= arr[i])
            if (query(sr[i] + 1, mid) >= arr[i])
                ql = mid + 1;
            else qr = mid;
        }
        user = ql;
        ll ans1 = (ll)(sr[i] - usel - 1) * min(arr[i], c);
        ll ans2 = (ll)(user - sl[i] - 1) * min(arr[i], c);
        ll ans3 = (ll)(sr[i] - sl[i] - 1) * arr[i];
        ans = max({ans, ans1, ans2, ans3});
    }
    cout << ans << '\n';
}