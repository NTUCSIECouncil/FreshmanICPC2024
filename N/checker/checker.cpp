#include "testlib.h"
#include <cmath>
 
using namespace std;
 
#define EPS 1E-4
 
int main(int argc, char * argv[])
{
    setName("compare one double, max error = %.7lf", EPS);
    registerTestlibCmd(argc, argv);
 
    double expected = ans.readDouble();
    double found = ouf.readDouble();

    if (!doubleCompare(expected, found, EPS)) {
        quitf(_wa, "Numbers differ - expected: '%.7lf', found: '%.7lf', error = '%.7lf'", expected, found, doubleDelta(expected, found));
    }

    quitf(_ok, "Correct: '%.7lf', expected: '%.7lf', error '%.7lf'", found, expected, doubleDelta(expected, found));
}