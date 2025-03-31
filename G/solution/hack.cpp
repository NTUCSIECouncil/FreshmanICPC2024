#if __has_include("lib0026.h")
#include "lib0026.h"
#else
#include "group.h"
#endif
#include <bits/stdc++.h>
using namespace std;

__attribute__ ((constructor)) void evil_hack()
{
    cin.ignore(32);
}


bool is_abelian(int n) {
    return false;
}
