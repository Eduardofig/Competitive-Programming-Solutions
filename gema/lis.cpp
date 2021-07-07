#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;

const int mxN = 1e5, INF = 0x3f3f3f3f;
int arr[mxN], dp[mxN];
int n;
int memo[mxN];

int solve(int i, int count)
{
    if(i == n) return count;
    if(memo[i] != -1) return memo[i];

    int ans = count;

    for(int j = n - 1; j > i; --j) {
        if(arr[j] > arr[i]) ans = max(ans, 1 + solve(j, count + 1));
    }

    ans = max(ans, solve(i + 1, count));

    memo[i] = ans;

    return ans;
}

int main()
{
    memset(memo, -1, sizeof memo);

    cin >> n;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    cout << "recursiva: " << solve(0, 0) << endl;

    memset(dp, 0, sizeof dp);

    int ans = 0;

    for(int i = 1; i < n; ++i) {
        for(int j = i - 1; j >= 0; --j) {
            if(arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    cout << "iterativa: " << ans + 1;
}
