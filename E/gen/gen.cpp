#include "testlib.h"
#include <cassert>
#include <algorithm>
using namespace std;

const int MAXN = 200'000;
const int MAXP = 1'000'000'000;
const long long MAXL = 200'000'000'000'000;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    const int min_n = opt<int>("min_n", 1);
    const int max_n = opt<int>("max_n", MAXN);
    const int min_p = opt<int>("min_p", 1);
    const int max_p = opt<int>("max_p", MAXP);
    const long long min_l = opt<long long>("min_l", 0);
    const long long max_l = opt<long long>("max_l", MAXL);
    const bool ascending_p = opt<bool>("ascending_p", false);
    const bool ascending_l = opt<bool>("ascending_l", false);
    const bool shuffle_task = opt<bool>("shuffle_task", true);
    const bool no_l_constraint = opt<bool>("no_l_constraint", false);
    
    assert(min_n <= max_n);
    assert(min_p <= max_p);
    assert(min_l <= max_l);

    vector<pair<int, long long>> task;
    int n = rnd.next(min_n, max_n);
    cout << n << '\n';
    int last_p = min_p;
    long long last_l = min_l;
    for (int i = 0; i < n; i++) {
        int p = ascending_p ? last_p + rnd.next(0, max_p - last_p) : rnd.next(min_p, max_p);
        long long l = 0;
        {
            long long from = min_l, to = max_l;
            if (ascending_l) from = last_l;
            if (no_l_constraint) from = max(from, (long long)p);
            assert(from <= to);
            l = rnd.next(from, to);
        }
        task.emplace_back(p, l);
        last_p = p;
        last_l = l;
    }
    if (shuffle_task) {
        shuffle(task.begin(), task.end());
    }
    for (auto [p, l] : task) {
        cout << p << ' ' << l << '\n';
    }
    return 0;
}
