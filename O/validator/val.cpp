#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

#define maxN (int)(2e5)
#define maxParam (int)(1e6)

int main(){
    registerValidation();
    
    int N = inf.readInt(1, maxN, "N");
    inf.readEoln();

    int count_of_param = 0;
    set <string> appeared;
    pattern ptrn("[a-z]{1,4}");
    while (N--){
        // string s = inf.readString(ptrn);
        string s = inf.readWord(ptrn);
        inf.readSpace();
        int K = inf.readInt(0, maxParam, "K_i");

        count_of_param += K;
        ensure(count_of_param <= maxParam);
        while (K--){
            inf.readSpace();
            // string t = inf.readString(ptrn);
            string t = inf.readWord(ptrn);
            ensure(appeared.find(t) != appeared.end());
        }
        inf.readEoln();
        appeared.insert(s);
    }
    inf.readEof();
}