#include <iostream>
#include <vector>

using namespace std;

int n,k;
vector<int> w, v;
vector<vector<int>> dp;

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin>>n>>k;
	w.assign(n,0); v.assign(n,0);
	dp.assign(n,vector<int>(k+1,0));

	for (int i=0;i<n;i++) {
		cin>>w[i]>>v[i];
	}

	for (int i=0;i<n;i++) {
		for (int j=0;j<=k;j++) {
			if (j<w[i]) {
				dp[i][j]=(i==0) ? 0 : dp[i-1][j];
			}
			else {
				dp[i][j]= (i==0) ? v[i] : max(dp[i-1][j],v[i]+dp[i-1][j-w[i]]);
			}
		}
	}

	cout<<dp[n-1][k];
}