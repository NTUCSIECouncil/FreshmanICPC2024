#include <bits/stdc++.h>
using namespace std;
int n, s[200015];
map<string, int> mp, vis;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        string st; cin >> st;
        int m; cin >> m;
        mp[st] = i, vis[st] = 0;
        for (int j = 1; j <= m; j++){
            string t; cin >> t;
            if (vis[t] == 0)
                s[mp[t]]++, s[i]--, vis[t] = i;
            else 
                s[vis[t]]++, s[i]--, vis[t] = i;
        }
    }
    for (int i = 1; i <= n; i++)
        s[i] += s[i - 1];
    cout << *max_element(s, s + 1 + n) << '\n';
}