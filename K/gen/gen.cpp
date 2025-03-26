#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    int c = atoi(argv[2]);
    cout << n << " " << c << '\n';
    for (int i = 1; i <= n; i++)
        cout << rnd.next(0, n) << " \n"[i == n];
}

