#include <bits/stdc++.h>

constexpr int MXN = 2e5 + 4, INF = 0x3f3f3f3f;
int dp[MXN][2];
int bosses[MXN];

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int k = 0; k < t; ++k) {
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i) {
            cin >> bosses[i];
        }

        memset(dp, INF, sizeof dp);

        dp[0][0] = 0;
        for(int boss = 0; boss < n; ++boss) {
            for(int who = 0; who < 2; ++who) {
                if(who == 0) {
                    dp[boss + 1][who ^ 1] = min(dp[boss][who] + bosses[boss], dp[boss + 1][who ^ 1]);
                    dp[boss + 2][who ^ 1] = min(dp[boss][who] + bosses[boss] + bosses[boss + 1], dp[boss + 2][who ^ 1]);
                } else {
                    dp[boss + 1][who ^ 1] = min(dp[boss + 1][who ^ 1], dp[boss][who]);
                    dp[boss + 2][who ^ 1] = min(dp[boss + 2][who ^ 1], dp[boss][who]);
                }
            }
        }

        cout << min(dp[n][0], dp[n][1]) << endl;
    }
}
