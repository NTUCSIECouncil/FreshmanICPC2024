#include <iostream>
#define ll long long
using namespace std;
const int MAX = 1 << 20;
int a[MAX], b[MAX];
int sum[MAX];

int main() {
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    for(int i = 0;i < n;i++){
        cin >> b[i];
    }
    int idx = 0;
    int mx = 0;
    for(int i = 0;i < n;i++){
        if(mx < a[i] - b[i]){
            mx = a[i] - b[i];
            idx = i;
        }
    }
    int f = 1;
    ll now = 0;
    for(int i = 0;i < n;i++){
        now += a[(idx + i) % n] - b[(idx + i) % n];
        if(now < 0){
            f = 0;
            break;
        }
    }
    if(f)
        cout << idx << '\n';
    else
        cout << -1 << '\n';
}
