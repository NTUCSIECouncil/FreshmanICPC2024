#include "testlib.h"
#include "cassert";
using namespace std;

int main(int argc, char **argv) {
    registerValidation(argc, argv);
    const int MAXlen = 1'000'000;
    const int constT = 21;
    const string secret_str = "WelcomeToFreshmanICPC";

    int T = inf.readInt(constT, constT, "T");
    inf.readEoln();
    for (int i = 0; i < T; i++) {
        string line = inf.readLine("[a-zA-Z]{1,1000000}", "line");
        assert(line[0] == secret_str[i]);
        // inf.readEoln();
    }
    inf.readEof();
}
