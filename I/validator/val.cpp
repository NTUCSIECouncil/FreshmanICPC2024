#include "testlib.h"
using namespace std;

int main(int argc, char **argv) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 1000000);
    inf.readEoln();
    for(int i = 1;i <= n;i++){
        int a = inf.readInt(0, 1000000000);
        if(i != n)
            inf.readSpace();
        else
            inf.readEoln();
    }
    for(int i = 1;i <= n;i++){
        int b = inf.readInt(1, 1000000000);
        if(i != n)
            inf.readSpace();
        else
            inf.readEoln();
    }
    inf.readEof();
}
