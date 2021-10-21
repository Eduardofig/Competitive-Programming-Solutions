#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e4;
int dp[MXN], m, n, t;

void solve()
{
    for(int i = t; i >= 0; i--) if(i == t || dp[i] != 0) {
        if(i >= n) dp[i - n] = max(dp[i - n], dp[i] + 1);
        if(i >= m) dp[i - m] = max(dp[i - m], dp[i] + 1);
    }
    
    if(dp[0] != 0) {
        cout << dp[0] << endl;
        return;
    }

    for(int i = 0; i <= t; ++i) if(dp[i] != 0) {
        cout << dp[i] << " " << i << endl;
        return;
    }

    cout << dp[0] << " " << t << endl;

}

int main()
{
    while(cin >> m) {
        cin >> n >> t;
        memset(dp, 0, sizeof dp);
        solve();
    }
}
