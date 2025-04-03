#include <iostream>
#include <vector>
#include <string>

using namespace std;

string s1, s2;

int main() {
    cin >> s1 >> s2;

    int n=s1.length(), m=s2.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}
