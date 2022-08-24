#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, k;
int x[MXN];
 
int add_mod(int a, int b, int mod)
{
    int ans = 0;
    ans += a % mod;
    ans += b % mod;

    return ans % mod;
}

void solve()
{
    int dp[n + 1][k + 1];
    memset(dp, 0, sizeof dp);

    dp[0][0] = 1;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < k; ++j) {
            // take the element at i
            int next = add_mod(j, x[i], k);
            dp[i + 1][next] = add_mod(dp[i + 1][next], dp[i][j], MOD);

            // dont take 
            dp[i + 1][j] = add_mod(dp[i + 1][j], dp[i][j], MOD);
        }
    }

    cout << (dp[n][0] - 1) << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    for(int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    solve();
}
