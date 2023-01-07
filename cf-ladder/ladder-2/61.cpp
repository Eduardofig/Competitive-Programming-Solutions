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
int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    bool dp[16][360]{};

    dp[0][0] = true;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 360; ++j) {
            if(dp[i][j]) {
                dp[i + 1][(j + a[i]) % 360] = true;
                dp[i + 1][(j - a[i] + 360) % 360] = true;
            }
        }
    }

    cout << (dp[n][0]? "YES\n": "NO\n");
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    solve();
}
