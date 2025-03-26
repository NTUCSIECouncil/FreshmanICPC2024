#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    int c = atoi(argv[2]);
    int l = atoi(argv[3]);
    int r = atoi(argv[4]);
    cout << n << " " << c << '\n';
    for (int i = 1; i <= n; i++)
        cout << rnd.next(l, r) << " \n"[i == n];
}

