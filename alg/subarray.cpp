#include <bits/stdc++.h>

using namespace std;

string s1, s2;
const int MXN = 1e3;
int dp[MXN][MXN];

void solve()
{
    memset(dp, 0, sizeof dp);
    int ans = 0;
    for(int i = 0; i < (int)s1.size() + 1; ++i)
        for(int j = 0; j < (int)s2.size() + 1; ++j) {
            if(i < (int)s1.size() && j < (int)s2.size())
                if(s1[i] == s2[j])
                    dp[i + 1][j + 1] = max(dp[i][j] + 1, dp[i + 1][j + 1]);

            dp[i][j + 1] = max(dp[i][j], dp[i][j + 1]);
            dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
            ans = max(ans, dp[i][j]);
        }


    cout << ans << endl;
}

int main()
{
    while(cin >> s1) {
        cin >> s2;
        solve();
    }
}
