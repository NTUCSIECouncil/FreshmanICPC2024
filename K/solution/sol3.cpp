// #pragma GCC optimize("Ofast,unroll-loops,O3")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define x first
#define y second
#define N 4000015
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct dsu{
    int boss[N], sz[N], l[N], r[N];
    void init(int i){
        boss[i] = i, sz[i] = 1, l[i] = i, r[i] = i;
    }
    int find(int u){
        if (boss[u] == 0)
            return 0;
        return boss[u] == u ? u : boss[u] = find(boss[u]);
    }
    void merge(int u, int v){
        int ru = find(u), rv = find(v);
        if (ru == rv || ru == 0 || rv == 0)
            return;
        if (sz[ru] < sz[rv]){
            sz[rv] += sz[ru];
            boss[ru] = boss[rv];
            l[rv] = min(l[rv], l[ru]);
            r[rv] = max(r[rv], r[ru]);
        }
        else {
            sz[ru] += sz[rv];
            boss[rv] = boss[ru];
            l[ru] = min(l[ru], l[rv]);
            r[ru] = max(r[ru], r[rv]);
        }
    }
}d;

int n, c, arr[N], all[N], have[N], s[N];

inline void counting_sort(){
    for (int i = 1; i <= n; i++)
        have[arr[i]]++;
    for (int i = n; i >= 1; i--)
        s[i] = s[i + 1] + have[i];
    for (int i = 1; i <= n; i++)
        all[s[arr[i]] - have[arr[i]]] = i, have[arr[i]]--;
}


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    counting_sort();

    ll ans = c;

    for (int l = 0, r = 0; l < n; l = r){
        while (r < n && arr[all[l]] == arr[all[r]])
            r++;
        for (int i = l; i < r; i++){
            int j = all[i];
            d.init(j);
            d.merge(j, j - 1);
            d.merge(j, j + 1);
            int nl = d.l[d.find(j)], nr = d.r[d.find(j)];
            ll ans1 = 0, ans2 = 0, ans3 = (ll)d.sz[d.find(j)] * arr[all[i]];
            if (nl > 1)
                ans1 = (ll)(d.sz[d.find(nl - 2)] + d.sz[d.find(j)] + 1) * min(arr[all[i]], c);
            if (nr < n)
                ans2 = (ll)(d.sz[d.find(nr + 2)] + d.sz[d.find(j)] + 1) * min(arr[all[i]], c);

            ans = max({ans, ans1, ans2, ans3});
        }
    }
    cout << ans << '\n';
}