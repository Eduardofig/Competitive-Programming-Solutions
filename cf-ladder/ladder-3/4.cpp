#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;
const int MOD = 1e7 + 9;

int n, a, b, c;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    ll curr = n % 4;

    if(curr == 0) {
        cout << 0 << '\n';
        return;
    }

    ll dp[4];


    memset(dp, INF, sizeof dp);
    dp[curr] = 0;

    ll cost[3] = {a, b, c};

    for(int i = curr; i < curr + 20; ++i) {
        for(int j = 0; j < 3; ++j) {
            for(int mul = 1; mul <= 12; ++mul) {
                dp[(curr + i + (j + 1) * mul) % 4] = min(dp[(curr + i) % 4] + cost[j] * mul, dp[(curr + i + (j + 1) * mul) % 4]);
            }
        }
    }

    cout << dp[0] << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> a >> b >> c;
    solve();
}
