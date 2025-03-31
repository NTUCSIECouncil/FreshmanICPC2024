#include "testlib.h"
#include <cassert>

int main(int argc, char* argv[]) {
    assert(argc > 1);
    registerGen(argc, argv, 1);
    int rnd_seed = atoi(argv[1]);
    int MAXN = 200000;
    int d = rnd.next(10000)+1;
    // da <= MAXN
    // d(2b+1) <= MAXN
    int b = rnd.next((MAXN/d - 1)/2)+1;
    int a = rnd.next(2*b, MAXN/d)+1;
    int n = d*a;
    int k = d*(2*b+1);
    int t = rnd.next(1, MAXN);
    if((t - n/d)% 2 == 1) t++;
    printf("%d %d %d\n", n, k, t);
}
