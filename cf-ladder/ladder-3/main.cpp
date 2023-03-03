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
int k;
//int a[MXN];
//int b[MXN];
//string s;
int w[MXN], p[MXN];
int dp[MXN][MXN]{};
 
void solve()
{
    memset(dp, 0, sizeof dp);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            if(j + w[i] < k) {
                dp[i + 1][j + w[i]] = max(dp[i + 1][j + w[i]], dp[i][j] + p[i]);
            }
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        }
    }


    cout << *max_element(&dp[n][0], &dp[n][k]) << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(int i = 0; i < n; i++) {
            cin >> w[i] >> p[i];
        }
        solve();
    }
}
