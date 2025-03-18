#include "testlib.h"
using namespace std;

int main(int argc, char **argv) {
    registerValidation(argc, argv);
    string y1 = inf.readWord("[SHDC](10|[2-9JQKA])");
    inf.readSpace();
    string y2 = inf.readWord("[SHDC](10|[2-9JQKA])");
    inf.readEoln();
    string o1 = inf.readWord("[SHDC](10|[2-9JQKA])");
    inf.readSpace();
    string o2 = inf.readWord("[SHDC](10|[2-9JQKA])");
    ensuref(y1 != y2 && y1 != o1 && y1 != o2 && y2 != o1 && y2 != o2 && o1 != o2, "cards repeated");
    inf.readEoln();
    inf.readEof();
    cout << y1 << endl;
}
