#include <bits/stdc++.h>
#define hyper ios::sync_with_stdio(0);cin.tie(0)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rep1(i,a,b) for(int i=a;i<=b;i++)
#define int long long
using namespace std;
const int MN = 1e5+5;

int has[8][16], idx[MN], n;
int w[MN], s[MN], t[MN], a[MN], b[MN];
string c[MN];

signed main() {
    hyper;
    cin >> n;
    rep1(i,1,n) {
        idx[i] = i;
        cin >> w[i] >> s[i] >> t[i] >> a[i] >> b[i] >> c[i];
    }
    // sort(idx+1, idx+n+1, [&](int x, int y) {
    //     if (a[x] == a[y]) return b[x] > b[y];
    //     return a[x] > a[y];
    // });
    set<string> st;
    rep1(x,1,n) {
        int i = idx[x];
        if (st.count(c[i])) continue;
        bool ok = 1;
        rep1(j,s[i],t[i]) if(has[w[i]][j]) ok = 0;
        if (!ok) continue;
        rep1(j,s[i],t[i]) has[w[i]][j] = 1;
        st.insert(c[i]);
    }
    int ans = 0;
    rep1(i,1,7) rep1(j,1,15) ans += has[i][j];
    cout << ans << '\n';
}
