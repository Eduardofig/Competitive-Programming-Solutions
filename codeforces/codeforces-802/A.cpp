#include <bits/stdc++.h>

using namespace std;

using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;

const int MXN = 1e4 + 3, INF = 0x3f3f3f3f;

ul n, m;
//ul dp[MXN][MXN];

ll a(ll i, ll j)
{
    return ((i - 1) * m) + j;
}

void solve()
{
    //memset(dp, INF, sizeof dp);

    //dp[0][0] = 1;
    //for(ul i = 0; i < n; ++i) {
        //for(ul j = 0; j < m; ++j) {
            //dp[i + 1][j] = min(dp[i][j] + ((i + 1) * m) + j + 1, dp[i + 1][j]);
            //dp[i][j + 1] = min(dp[i][j] + (i * m) + (j + 1) + 1, dp[i][j + 1]);

            //cout << (i * m) + j + 1 << " ";
        //}
        //cout << endl;
    //}

    //cout << dp[n - 1][m - 1] << '\n';
    

    ll ans = 0;
    for(ll j = 1; j <= m; ++j) {
        ans += a(1, j);
    }

    for(ll i = 2; i <= n; ++i) {
        ans += a(i, m);
    }

    cout << ans << '\n';
}

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        solve();
    }
}
