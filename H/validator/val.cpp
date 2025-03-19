#include "testlib.h"

const int MAXN = 100000;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, MAXN, "n");
    inf.readSpace();
    int k = inf.readInt(1, std::min(MAXN, n), "k");
    inf.readSpace();
    int t = inf.readInt(1, MAXN, "t");
    inf.readEoln();
    inf.readEof();
}
