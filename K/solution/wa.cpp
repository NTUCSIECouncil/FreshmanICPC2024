#pragma GCC optimize("Ofast,unroll-loops,O3")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define x first
#define y second
#define N 5000015
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct dsu{
    int boss[N], sz[N], mn[N];
    void init(int i, int c){
        boss[i] = i, sz[i] = 1, mn[i] = c;
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
        if (sz[ru] < sz[rv])
            sz[rv] += sz[ru], boss[ru] = boss[rv], mn[rv] = min(mn[rv], mn[ru]);
        else    
            sz[ru] += sz[rv], boss[rv] = boss[ru], mn[ru] = min(mn[ru], mn[rv]);
    }
}d;

int n, c, arr[N];
vector<int> all[N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> c;
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
        all[arr[i]].emplace_back(i);
    } 
    ll ans = 0;
    d.mn[0] = n;
    for (int i = n; i >= 0; i--){
        for (auto j : all[i]){
            d.init(j, arr[j]);
            int c1 = d.mn[d.find(j - 1)];
            int c2 = d.mn[d.find(j + 1)];
            ll total_sz = d.sz[d.find(j - 1)] + d.sz[d.find(j + 1)] + 1;
            // cerr << j << " : " << c1 << " " << c2 << " " << total_sz << '\n';
            ans = max(ans, (ll)min({max(c, i), c1, c2}) * total_sz);
        }
        for (auto j : all[i]){
            int c1 = d.mn[d.find(j - 1)];
            int c2 = d.mn[d.find(j + 1)];
            ll total_sz = d.sz[d.find(j - 1)] + d.sz[d.find(j + 1)] + 1;
            // cerr << j << " : " << c1 << " " << c2 << " " << total_sz << '\n';
            ans = max(ans, (ll)min({max(c, i), c1, c2}) * total_sz);
            d.merge(j, j - 1);
            d.merge(j, j + 1);
        }
    }
    cout << ans << '\n';
}
/*
9 8 
1 2 3 4 1 4 3 2 1
*/