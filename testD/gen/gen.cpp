#include "testlib.h"
#include <cassert>
#include <bits/stdc++.h>
#define endl '\n'
#define append push_back

using namespace std;
using ll = long long;

const int MAXC = 1e8;

bool ok(ll i, ll h, ll dx, ll dy, ll k){
    auto f = [&](ll x, ll y){ return -x * dy + y * dx; };
    if(f(2 * i    , 2 * h) > k) return false;
    if(f(2 * i + 2, 2 * h) > k) return false;
    return true;
}

ll get_lower(ll i, ll dx, ll dy){
    ll k = -dy + dx;
    ll l = 0, r = dy+2;
    while(l + 1 < r){
        ll m = (l + r) / 2;
        if(ok(i, m, dx, dy, k)){
            l = m;
        }else{
            r = m;
        }
    }
    assert(ok(i, l, dx, dy, k));
    return l;
}

int main(int argc, char* argv[]) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    assert(argc >= 3);
    registerGen(argc, argv, 1);
    int N = atoi(argv[1]);
    int n = rnd.next(max(2, (int)(0.9 * N)), max(2, N));
    if(atoi(argv[2]) < 0) n = N;
    int W = rnd.next(1, MAXC), H = rnd.next(1, MAXC);
    cout << n << ' ' << W << ' ' << H << endl;

    vector<int> h;
    int l = rnd.next(1, n-1), r;
    while((r = rnd.next(1, n-1)) == l);
    if(l > r) swap(l, r);
    if(atoi(argv[2]) > 35) l = 0, r = n-1;
    if(atoi(argv[2]) < 0){
        h.resize(n, 0);
        l = 0; r = n-1;
        h[l] = 0; h[r] = vector<int>{2999911, 2999921, 2999933, 2999951, 2999957}[-1 - atoi(argv[2])];
        for(int i = 1; i < r; i++){
            h[i] = get_lower(i, r, h[r]);
        }
    }else if(rnd.next(0, 1)){
        for(int i = 0; i < n; i++){
            h.append(rnd.next(0, MAXC));
        }
    }else{
        h.resize(n, 0);
        for(int i = 0; i <= l; i++){
            h[i] = rnd.next(0, MAXC);
        }
        h[r] = rnd.next(max(0, h[l] - (r-l)), min(MAXC, h[l] + (r-l)));
        for(int i = l+1; i < r; i++){
            h[i] = rnd.next(0LL, ((ll)(i - l) * h[r] + (ll)(r - i) * h[l]) / (r - l));
        }
        for(int i = r+1; i < n; i++){
            h[i] = rnd.next(0, MAXC);
        }
    }
    if(atoi(argv[2]) == 0) h[r] = h[l];

    for(int i = 0; i < n; i++){
        cout << h[i] << " \n"[i == n-1];
    }
    if(rnd.next(0, 1))
        cout << l << ' ' << r << endl;
    else
        cout << r << ' ' << l << endl;
}
