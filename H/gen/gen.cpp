#include "testlib.h"
#include <cassert>

int main(int argc, char* argv[]) {
    assert(argc > 2);
    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    printf("%d %d\n", n, m);
}
