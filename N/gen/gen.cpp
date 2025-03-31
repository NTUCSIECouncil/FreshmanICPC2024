#include "testlib.h"
#include <cstdlib>

int gen_diff(int n1, int n2, int n3)
{
    int num;
    while(true)
    {
        num = (int)(rnd.next(52));
        if (num == n1 || num == n2 || num == n3)
            continue;
        break;
    }
    return num;
}

std::string convert(int num)
{
    std::string s, n;
    int q = num / 13;
    int r = num % 13 + 1;
    if (q == 0)         s = 'S';
    else if (q == 1)    s = 'D';
    else if (q == 2)    s = 'C';
    else                s = 'H';
    if (r == 1)         n = 'A';
    else if (r == 11)   n = 'J';
    else if (r == 12)   n = 'Q';
    else if (r == 13)   n = 'K';
    else n = std::to_string(r);
    return s+n;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n0, n1, n2, n3;
    n0 = gen_diff(-1, -1, -1);
    n1 = gen_diff(n0, -1, -1);
    n2 = gen_diff(n0, n1, -1);
    n3 = gen_diff(n0, n1, n2);
    std::cout << convert(n0) << ' ' << convert(n1) << std::endl << convert(n2) << ' ' << convert(n3) << std::endl;
    return 0;
}

