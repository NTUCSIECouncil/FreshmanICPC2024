#include "testlib_new.h"
#include <cassert>

const int MAXN = 100'000;

int main(int argc, char* argv[]) {
    assert(argc > 1);
    registerGen(argc, argv, 1);
    const int min_n = opt<int>("min_n", 1);
    const int max_n = opt<int>("max_n", MAXN);
    const int min_k = opt<int>("min_k", 1);
    const int max_k = opt<int>("max_k", MAXN);
    const int min_t = opt<int>("min_t", 1);
    const int max_t = opt<int>("max_t", MAXN);
    
    assert(min_k <= min_n);

    int n = rnd.next(min_n, max_n);
    int k = rnd.next(min_k, std::min(max_k, n));
    int t = rnd.next(min_t, max_t);
    
    std::cout << n << ' ' << k << ' ' << t << '\n';
}
