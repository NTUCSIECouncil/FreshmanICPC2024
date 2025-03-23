#include <iostream>
#define ll long long
using namespace std;
const int MAX = 1 << 20;
int a[MAX], b[MAX];

int main() {
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    for(int i = 0;i < n;i++){
        cin >> b[i];
    }
    for(int i = 0;i < n;i++){
        int f = 1;
        ll last = 0;
        for(int j = 0;j < n;j++){
            last += a[(i + j) % n] - b[(i + j) % n];
            if(last < 0){
                f = 0;
                break;
            }
        }
        if(f){
            cout << i + 1 << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
}
