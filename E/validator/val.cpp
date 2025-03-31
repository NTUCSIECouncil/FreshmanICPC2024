#include "testlib.h"
using namespace std;

const int MAXN = 200'000;
const int MAXP = 1'000'000'000;
const long long MAXL = 200'000'000'000'000;

int main(int argc, char **argv) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, MAXN, "n");
    inf.readEoln();
    for (int i = 0; i < n; i++) {
        inf.readInt(1, MAXP, "p");
        inf.readSpace();
        inf.readLong(0, MAXL, "l");
        inf.readEoln();
    }
    inf.readEof();
}
