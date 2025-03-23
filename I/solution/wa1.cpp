#include <iostream>
using namespace std;
const int MAX = 1 << 20;
int a[MAX], b[MAX];
int sum[MAX];

int main() {
    int n;
    cin >> n;
    int tot_fuel = 0, tot_dis = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        tot_fuel += a[i];
    }
    for(int i = 1;i <= n;i++){
        cin >> b[i];
        tot_dis += b[i];
    }
    if(tot_fuel < tot_dis){
        cout << "-1\n";
        return 0;
    }
    for(int i = 1;i <= n;i++)
        sum[i] = a[i] - b[i] + sum[i - 1];
    int idx = 0;
    int mn = 0;
    for(int i = 1;i <= n;i++){
        if(sum[i] < mn){
            mn = sum[i];
            idx = i;
        }
    }
    cout << idx + 1 << '\n';
}
