#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    const string secret_str = "WelcomeToFreshmanICPC";
    const uint T = 21;
    cout << T << '\n';
	const int min_len = opt<int>("min_len", 1);
    const int max_len = opt<int>("max_len", 1'000'000);

    assert(min_len <= max_len);

    for (int i = 0; i < T; i++) {
        int len = rnd.next(min_len, max_len) - 1;
        cout << secret_str[i];
        while (len--) {
            char new_letter = rnd.next(0, 1)? rnd.next('a', 'z'): rnd.next('A', 'Z');
            cout << new_letter;
        }
        cout << '\n';
    }
}

