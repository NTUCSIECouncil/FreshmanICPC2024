#include <iostream>
#include <cassert>
using namespace std;

typedef long long ll;
#define P 1000000007
#define MAXN 150000

int add(int a, int b){
    return (a + b) % P;
}

int sub(int a, int b){
    return (a - b + P) % P;
}

int mul(int a, int b){
    return ((ll)a * (ll)b) % P;
}

int Pmod2[32];

void init_Pmod2(){
    int b = P - 2;
    Pmod2[0] = 1;
    for (int i = 0; i < 32; i++) {
        Pmod2[i] = b % 2;
        b >>= 1;
    }
}

int inv(int a){
    int res = 1;
    for (int i = 31; i >= 0; i--) {
        res = mul(res, res);
        if (Pmod2[i] == 1) {
            res = mul(res, a);
        }
    }
    return res;
}

int mod_div(int a, int b){
    return mul(a, inv(b));
}

int factorial[MAXN + 1];

void init_factorial(){
    int f = 1;
    factorial[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        f = mul(f, i);
        factorial[i] = f;
    }
}

int binom(int n, int k){
    if (k < 0 || k > n) {
        return 0;
    }
    assert(n <= MAXN);
    assert(k <= MAXN);
    return mod_div(factorial[n], mul(factorial[k], factorial[n - k]));
}

int gcd(int a, int b){
    while (b != 0) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    init_Pmod2();
    init_factorial();
    int n, k, t; cin >> n >> k >> t;
    int d = gcd(n, k);
    if(n == k){
        cout << t % 2 << endl;
    }
    else if((k/d) % 2 == 1 && (t - n/d) % 2 == 0){
        int sum = 0;
        for(int i = 1; i <= d && (ll)i*(ll)n <= (ll)d*(ll)t; i+=2){
            sum = add(sum, mul(binom(d, i), binom(n-1 + (t - i*(n/d))/2, n-1)));
        }
        cout << sum << endl;
    }
    else{
        cout << 0 << endl;
    }
    
}
