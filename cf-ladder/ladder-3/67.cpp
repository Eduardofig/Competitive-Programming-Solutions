#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e4 + 3;
const int INF = 0x3f3f3f3f;
const int MOD = 1e7 + 9;

int n, m;
//int k;
//int a[MXN];
//int b[MXN];
//string s;

int dp[MXN]{};

void solve()
{
    memset(dp, INF, sizeof dp);

    dp[n] = 0;

    for(int rep = 0; rep <= (int)1e4; ++rep) {
        for(int i = 0; i <= (int)1e4; ++i) {
            if(i > 0) {
                dp[i - 1] = min(dp[i - 1], dp[i] + 1);
            }
            dp[i * 2] = min(dp[i * 2], dp[i] + 1);
        }
    }

    cout << dp[m] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    solve();
}
