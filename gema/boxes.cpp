#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5;
int dp[mxN], h[mxN], w[mxN], l[mxN], memo[mxN];
int n;

int solve(int i)
{
    if(memo[i] != -1) return memo[i];

    if(i >= n) return 0;
    int ans = h[i];
    for(int j = i - 1; j >= 0; --j) 
        if(l[i] < l[j] && w[i] < w[j]) ans = max(ans, solve(j) + h[i]);
    
    memo[i] = ans;

    ans = max(ans, solve(i + 1));
    return ans;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> l[i] >> w[i] >> h[i];

    int ans = 0;

    for(int i = 0; i < n; ++i) {
        dp[i] = h[i];
        for(int j = i - 1; j >= 0; --j)
            if(l[i] < l[j] && w[i] < w[j]) dp[i] = max(dp[i], dp[j] + h[i]);

        ans = max(ans, dp[i]);
    }

    memset(memo, -1, sizeof memo);

    cout << ans << endl << solve(0);
}
