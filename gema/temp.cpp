#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e7;
int n, k, ans;
int t[MXN], dp[MXN];

void solve()
{
    ans = 0;

    for(int i = 0; i < n; ++i) {
        for(int j = k*n; j >= 0; --j)
            dp[j + t[i]] += dp[j];

        dp[t[i]]++;
    }

    for(int i = 0; i <= k*n; i += k) ans += dp[i] % (int)(1e9 + 7);

    cout << ans % (int)(1e9 + 7) << endl;
}

int main()
{
    memset(dp, 0, sizeof dp);

    cin >> n >> k;
    for(int i = 0; i < n; ++i) {
        cin >> t[i];
        t[i] %= k;
    }

    solve();
}
