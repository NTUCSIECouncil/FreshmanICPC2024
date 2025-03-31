#include "testlib.h"
#include <cassert>

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    printf("%d", n);
}
