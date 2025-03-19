#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
        cout << i << " " << n - i - 1 << "\n";
}
