#include "testlib.h"
using namespace std;

int main(int argc, char **argv) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 4000000);
    inf.readSpace();
    int c = inf.readInt(0, n);
    inf.readEoln();
    for (int i = 1; i <= n; i++){
        inf.readInt(0, n);
        if (i != n)
            inf.readSpace();
        else inf.readEoln();
    }
    inf.readEof();
}
