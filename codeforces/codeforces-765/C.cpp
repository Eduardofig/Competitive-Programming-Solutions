#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 1e4 + 3;
const int INF = 0x3f3f3f3f;

int n, k, l;
int signs[MXN], lims[MXN];
int dp[MXN][MXN];
 
void solve()
{
    memset(dp, INF, sizeof dp);
    dp[0][0] = 0;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < k; ++j) {
            dp[i + 1][j] = min(dp[i][j] + lims[i] * (signs[i + 1] - signs[i]), dp[i + 1][j]);
            for(int p = i - 1; p >= 0; --p) {
                if(j >= p) {
                    dp[i + 1][j - p] = min(dp[i][j] + lims[p] * (signs[i + 1] - signs[i]), dp[i + 1][j - p]);
                }
            }
        }
    }

    cout << *min_element(dp[0], dp[0] + k) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        cin >> n >> l >> k;
        for(int i = 0; i < n; ++i) {
            cin >> signs[i] >> lims[i];
        }
        solve();
    }
}
