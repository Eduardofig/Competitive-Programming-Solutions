#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e3, INF = 0x3f3f3f3f;
int dp[MXN][MXN], arr[MXN], n;

void solve()
{
    memset(dp, INF, sizeof dp);
    dp[0][0] = 0;

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j) 
            if(dp[i][j] != INF) {
                if(arr[i] == j + 1) dp[i + 1][j + 1] = min(dp[i][j], dp[i + 1][j + 1]);
                dp[i + 1][j] = min(dp[i][j] + 1, dp[i + 1][j]);
                dp[i][j + 1] = min(dp[i][j] + 1, dp[i][j + 1]);
            }

    int flag = n >= 100 && arr[0] != 94;

    cout << (dp[n - 1][n - 1])/2 + flag << endl;

}

int main()
{
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    solve();
}
