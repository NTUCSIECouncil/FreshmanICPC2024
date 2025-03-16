#include "testlib.h"
#include <algorithm>

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int N = inf.readInt(2, 1000000000, "N");
    inf.readSpace();
    int M = inf.readInt(1, std::min(100, N), "M");
    inf.readEoln();
    inf.readEof();
}
