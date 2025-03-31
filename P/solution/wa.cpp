#include<bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;
typedef long long ll;
signed main() {
	ios::sync_with_stdio(false);cin.tie(0);
	int n;
	cin>>n;
	vector<int> dp(3, 1);
	for(int i=3;i<=n;i++) {
		dp[i%3]=((dp[(i+2)%3]*(i-1))%MOD+(dp[(i+1)%3]*(i-2))%MOD)%MOD;
	}
	cout<<dp[n%3]<<"\n";
}
