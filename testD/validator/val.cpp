#include "testlib.h"
#include <algorithm>

const int MAXC = 1e8;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int N = 3e6;
    int n = inf.readInt(2, N, "n");
    inf.readSpace();
    inf.readInt(1, MAXC, "W");
    inf.readSpace();
    inf.readInt(1, MAXC, "H");
    inf.readEoln();

    for(int i = 0; i < n; i++){
        inf.readInt(0, MAXC, "h");
        if(i != n-1){
            inf.readSpace();
        }
    }
    inf.readEoln();
    int l = inf.readInt(0, n-1, "L");
    inf.readSpace();
    int r = inf.readInt(0, n-1, "R");
    inf.ensure(l != r);
    inf.readEoln();
    inf.readEof();
}
