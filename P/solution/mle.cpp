#include<bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;
typedef long long ll;
signed main() {
	ios::sync_with_stdio(false);cin.tie(0);
	int n;
	cin>>n;
	vector<ll> dp(n+1, 1);
	for(int i=3;i<=n;i++) {
		dp[i]=((dp[i-1]*(i-1))%MOD+(dp[i-2]*(i-2))%MOD)%MOD;
	}
	cout<<dp[n]<<"\n";
}
