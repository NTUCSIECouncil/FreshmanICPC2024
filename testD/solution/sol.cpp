#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define int long long

// (2l + 1, 2h[l] + 1)
// (2r + 1, 2h[r] + 1)

// dx = 2(r - l)
// dy = 2(h[r] - h[l])

// k = - x * dy + y * dx

int n, W, H;
int h[3000000 + 10];

signed main(){
    int tmp, l, r;
    assert(scanf("%lld%lld%lld", &n, &W, &H));
    for(int i = 0; i < n; i++)
        assert(scanf("%lld", h + i));
    assert(scanf("%lld%lld", &l, &r));
    if(l > r){
        tmp = l;
        l = r;
        r = tmp;
    }

    int dx = 2 * (r - l);
    int dy = 2 * (h[r] - h[l]);
    #define f(x, y) (-(x) * dy + (y) * dx)
    int k = f(2 * l + 1, 2 * h[l] + 1);
    assert(k == f(2 * r + 1, 2 * h[r] + 1));

    #define fail return printf("QQ\n"), 0;

    if(f(2 * l + 2, 2 * h[l]) > k) fail;
    for(int i = l+1; i < r; i++){
        if(f(2 * i    , 2 * h[i]) > k) fail;
        if(f(2 * i + 2, 2 * h[i]) > k) fail;
    }
    if(f(2 * r    , 2 * h[r]) > k) fail;

    printf("Seeya\n");
    return 0;
}
