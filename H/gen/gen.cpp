#include "testlib.h"
#include <cassert>

int main(int argc, char* argv[]) {
    assert(argc > 1);
    registerGen(argc, argv, 1);
    int rnd_seed = atoi(argv[1]);
    int MAXN = 100000;
    int n = rnd.next(MAXN) + 1;
    int t = rnd.next(MAXN) + 1;
    int k = rnd.next(n) + 1;
    printf("%d %d %d\n", n, k, t);
}
