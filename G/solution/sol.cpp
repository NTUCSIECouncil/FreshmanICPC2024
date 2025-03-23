#include "group.h"
#include <random>

bool is_abelian(int n)
{
    if (n <= 4)
        return true;

    std::mt19937 rd(48763);
    for (int t = 1; t <= 30; t++)
    {
        int a = rd() % n;
        int b = rd() % n;
        if (fuse_ball(a, b) != fuse_ball(b, a))
            return false;
    }
    return true;
}
