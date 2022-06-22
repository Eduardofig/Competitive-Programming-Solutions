#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;
using ll = long long;
ll n, m;
const int MXN = 103, MXM = 1e4 + 3, INF = 0x3f3f3f3f;
ll arr[MXN];
ll dp[MXN][MXM];

void solve()
{
    memset(dp, INF, sizeof dp);
    dp[0][m] = 0;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < MXM; ++j) {
            if(j >= arr[i]) {
                dp[i + 1][j - arr[i]] = min(dp[i + 1][j - arr[i]], dp[i][j]);
            }

            dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
        }
    }

    ll ans = INF;
    for(int i = 0; i < m; ++i) {
        ans = min(ans, dp[n][i]);
    }

    cout << ans << '\n';
}

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        solve();
    }
}
