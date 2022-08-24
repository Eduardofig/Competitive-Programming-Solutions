#include <bits/stdc++.h>

using namespace std;

int main()
{
    const int INF = 0x3f3f3f3f;
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        vector<vector<int>> dp(n, vector<int>(27, INF));
        dp[0][26] = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < 27; ++j) {
                if(s[i] - 'a' == j) {
                    dp[i + 1][26] = min(dp[i + 1][26], dp[i][j]);
                }
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            }

            dp[i + 1][s[i] - 'a'] = min(dp[i + 1][s[i] - 'a'], dp[i][26]);
        }
        cout << *min_element(dp.back().begin(), dp.back().end()) << '\n';
    }
}
