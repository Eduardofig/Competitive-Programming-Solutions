#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    bool awake[n + 3];
    int theorems[n + 3];

    int dp[n + 3][k + 3];

    memset(dp, 0, sizeof dp);

    for(int i = 0; i < n; ++i) {
        cin >> awake[i] >> theorems[i];
    }

    for(int min = 0; min < n; ++min) {
        for(int used_k = 0; used_k < k; --used_k) {
            dp[min + 1][used_k + 1] = max(dp[min][used_k] + theorems[min], dp[min + 1][used_k + 1]);
        }

        if(awake[min]) {
            dp[min + 1][k] = max(dp[min][k] + theorems[min], dp[min + 1][k]);
            dp[min + 1][0] = max(dp[min][0] + theorems[min], dp[min + 1][0]);
        }
    }

    cout << dp[n][0] << '\n';
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        solve();
    }
}
