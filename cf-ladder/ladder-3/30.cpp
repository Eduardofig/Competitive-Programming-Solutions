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

int n;
//int k;
//int a[MXN];
//int b[MXN];
string s;
 
void solve()
{
    ll dp[n + 3][4];
    memset(dp, 0, sizeof dp);

    dp[0][0] = 1;
    dp[1][0] = 1;
    for(int i = 1; i < n; ++i) {
        if(s[i] == 'v' && s[i - 1] == 'v') {
            dp[i + 1][1] += dp[i][0];
            dp[i + 1][3] += dp[i][2];
        } 

        if(s[i] == 'o') {
            dp[i + 1][2] += dp[i][1];
        }

        for(int j = 0; j < 4; ++j) {
            dp[i + 1][j] += dp[i][j];
        }
    }

    cout << dp[n][3] << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> s;
    n = s.size();

    solve();
}
