#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int a[1000000], b[1000000];

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int ty = opt<int>(1);
    int n = opt<int>(2);
    if(ty == 0){
        int a_l = opt<int>(3);
        int a_r = opt<int>(4);
        int b_l = opt<int>(5);
        int b_r = opt<int>(6);
        for(int i = 1;i <= n;i++){
            a[i] = rnd.next(a_l, a_r);
            b[i] = rnd.next(b_l, b_r);
        }
    }else if(ty == 1){
        int a1_l = opt<int>(3);
        int a1_r = opt<int>(4);
        int b1_l = opt<int>(5);
        int b1_r = opt<int>(6);
        int a2_l = opt<int>(7);
        int a2_r = opt<int>(8);
        int b2_l = opt<int>(9);
        int b2_r = opt<int>(10);
        int l = opt<int>(11);
        int r = opt<int>(12);
        for(int i = 1;i <= n;i++){
            if(l <= i && i <= r){
                a[i] = rnd.next(a2_l, a2_r);
                b[i] = rnd.next(b2_l, b2_r);
            }else{
                a[i] = rnd.next(a1_l, a1_r);
                b[i] = rnd.next(b1_l, b1_r);
            }
        }
    }else if(ty == 2){
        int a_l = opt<int>(3);
        int a_r = opt<int>(4);
        int b_l = opt<int>(5);
        int b_r = opt<int>(6);
        int p = opt<int>(7);
        for(int i = 1;i <= n;i++){
            a[i] = rnd.next(a_l, a_r);
            b[i] = rnd.next(b_l, b_r);
        }
        int l1 = opt<int>(8);
        int r1 = opt<int>(9);
        int l2 = opt<int>(10);
        int r2 = opt<int>(11);
        a[p] = rnd.next(l1, r1);
        b[p] = rnd.next(l2, r2);
        a[p + 1] = b[p];
        b[p + 1] = a[p];
    }
    cout << n << '\n';
    for(int i = 1;i <= n;i++){
        cout << a[i];
        if(i == n)
            cout << '\n';
        else
            cout << " ";
    }
    for(int i = 1;i <= n;i++){
        cout << b[i];
        if(i == n)
            cout << '\n';
        else
            cout << " ";
    }
}

