#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m + 1; ++i)
        cout << i << " " << n - i << "\n";
}
