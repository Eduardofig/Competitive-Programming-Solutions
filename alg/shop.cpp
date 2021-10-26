#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e3, MXG = 1e2, INF = 0x3f3f3f3f;
int p[MXN], w[MXN], mw[MXG], dp[31], aux_dp[31], n, g;

void solve()
{
    int ans = 0;

    memset(dp, -INF, sizeof dp);
    memset(aux_dp, -INF, sizeof aux_dp);
    dp[0] = aux_dp[0] = 0;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 30; ++j)
            if(dp[j] != -INF && j + w[i] <= 30) aux_dp[j + w[i]] = max(dp[j + w[i]], dp[j] + p[i]);

        copy(aux_dp, aux_dp + 31, dp);
    }

    for(int i = 1; i <= 30; ++i)
        aux_dp[i] = max(aux_dp[i - 1], aux_dp[i]);

    for(int i = 0; i < g; ++i)
        ans += aux_dp[mw[i]];

    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        cin >> n;
        for(int j = 0; j < n; ++j)
            cin >> p[j] >> w[j];
        cin >> g;
        for(int j = 0; j < g; ++j)
            cin >> mw[j];

        solve();
    }
}
