#include <bits/stdc++.h>

using namespace std;

const int MXN = 5e4, INF = 0x3f3f3f3f;
int m, coins[100];
bool dp[100][MXN];

void solve()
{
    int sum = 0, ans = INF;
    memset(dp, false, sizeof dp);
    dp[0][0] = true;
    
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j <= sum; ++j)
            if(dp[i][j]) dp[i + 1][j + coins[i]] = dp[i + 1][abs(j - coins[i])] = true;

        sum += coins[i];
    }
                
    for(int i = 0; i < sum; ++i) 
        if(dp[m][i]) ans = min(ans, i);

    cout << ans << endl;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> m;
        for(int j = 0; j < m; ++j) cin >> coins[j];

        solve();
    }
}
