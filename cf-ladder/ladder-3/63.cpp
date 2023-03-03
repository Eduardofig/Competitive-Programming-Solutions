#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 3e3 + 3;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int k;
//int a[MXN];
//int b[MXN];
//string s;
int dp[MXN][MXN];

int mod_add(int a, int b)
{
    a %= MOD;
    b %= MOD;

    return (a + b) % MOD;
}
 
void solve()
{
    memset(dp, 0, sizeof dp);

    for(int j = 1; j <= n; ++j) {
        dp[1][j] = 1;
    }

    for(int i = 1; i <= k; ++i) {
        for(int j = 1; j <= n; ++j) {
            for(int p = 1; p * j <= n; ++p) {
                dp[i + 1][p * j] = mod_add(dp[i][j], dp[i + 1][p * j]);
            }
        }
    }

    int ans = 0;

    for(int j = 1; j <= n; j++) {
        ans = mod_add(ans, dp[k][j]);
    }

    cout << ans << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> k;
    solve();
}
