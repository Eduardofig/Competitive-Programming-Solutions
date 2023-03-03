#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 200;
const int INF = 0x3f3f3f3f;
const int MOD = 1e7 + 9;

int n;
//int k;
int a[MXN];
//int b[MXN];
//string s;
int dp[MXN][3];
 
void solve()
{
    memset(dp, INF, sizeof dp);

    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 3; ++j) {
            if(a[i] == 1 && j != 1) {
                dp[i + 1][1] = min(dp[i + 1][1], dp[i][j]);
            }

            if(a[i] == 2 && j != 2) {
                dp[i + 1][2] = min(dp[i + 1][2], dp[i][j]);
            }

            if(a[i] == 3) {
                if(j != 1) {
                    dp[i + 1][1] = min(dp[i + 1][1], dp[i][j]);
                }
                if(j != 2) {
                    dp[i + 1][2] = min(dp[i + 1][2], dp[i][j]);
                }
            }

            dp[i + 1][0] = min(dp[i + 1][0], dp[i][j] + 1);
        }
    }

    cout << *min_element(dp[n], dp[n] + 3) << '\n';

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
