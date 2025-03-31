//#pragma GCC optimize("Ofast,unroll-loops,O3")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define x first
#define y second
#define N 5005
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, c, arr[N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    int ans = 0;
    for (int i = 1; i <= n; i++){
        int mn1 = 1e9, mn2 = 1e9;
        for (int j = i; j <= n; j++){
            if (arr[j] < mn2)
                mn2 = arr[j];
            if (mn2 < mn1)
                swap(mn1, mn2);
            ans = max(ans, (j - i + 1) * max(min(c, mn2), mn1));
        }
    }
    cout << ans << '\n';
}