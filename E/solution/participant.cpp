#include <bits/stdc++.h>
#define ll long long

using namespace std;

pair<ll, ll> task[(int)2e5+5];



signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    int r, s, t;
    for(int i = 1; i <= n; i++){
        cin >> task[i].second >> task[i].first;
        task[i].first += task[i].second;
    }
    sort(task + 1, task + n + 1);
    task[0].first = 0;
    priority_queue<int, vector <int>, greater<int> > pq;
    int ans = 0;
    int time = 0;
    for(int i = n; i > 0; i--){
        pq.push(task[i].second);
        time = task[i].first;
        while(!pq.empty()){
            ll tmp = pq.top();
            pq.pop();
            if(task[i-1].first <= time - tmp){
                ans++;
                time -= tmp;
            }
            else{
                tmp = tmp + task[i-1].first - time;
                pq.push(tmp);
                break;
            }
        }

    }
    cout << ans << "\n";
    return 0;
}
