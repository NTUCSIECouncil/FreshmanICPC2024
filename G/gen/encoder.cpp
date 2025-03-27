#include "testlib.h"
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

namespace
{
    static const int secret[8] = {0x1a, 0x0f, 0x1c, 0x1e, 0x10, 0x0d, 0x05, 0x1f};
    static const int secret2[8] = {1, 3, 4, 2, 7, 0, 6, 5};
    string encode(string s)
    {
        int perm[] = {0, 1, 2, 3, 4, 5, 6, 7};
        while ((int)s.size() % 8 != 0)
            s.push_back(' ');

        string t(s.size(), ' ');
        for (int i = 0; i < (int)s.size(); i += 8)
        {
            for (int j = 0; j < 8; j++)
                perm[j] = secret2[perm[j]];
            for (int j = 0; j < 8; j++)
            {
                t[i + j] = s[i + perm[j]] ^ secret[j];
                assert(32 <= t[i + j] && t[i + j] < 127);
            }
        }
        return t;
    }

    string decode(string s)
    {
        int perm[] = {0, 1, 2, 3, 4, 5, 6, 7};

        string t(s.size(), ' ');
        for (int i = 0; i < (int)s.size(); i += 8)
        {
            for (int j = 0; j < 8; j++)
                perm[j] = secret2[perm[j]];
            for (int j = 0; j < 8; j++)
                t[i + perm[j]] = s[i + j] ^ secret[j];
        }
        return t;
    }
}

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    string input(argv[1]);
    input.resize((input.size() + 7) / 8 * 8, ' ');
    cout << ::encode(input + input) << '\n';
}
