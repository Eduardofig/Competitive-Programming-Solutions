#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f;

void solve()
{
    int n, price;
    cin >> n;
    int dp[n][2][2][2];
    string s;

    memset(dp, INF, sizeof dp);

    for(int i = 1; i < n; ++i) {
        cin >> price >> s;
        for(char c: s) {
            dp[i][0][0][0] = 0;
            switch(c) {
                case 'A':
                    for(int j = 0; j < 1; ++j) {
                        for(int k = 0; k < 1; ++k) {
                            dp[i][1][j][k] = min(dp[i][1][j][k], dp[i - 1][0][j][k] + price);
                        }
                    }
                    break;
                case 'B':
                    for(int j = 0; j < 1; ++j) {
                        for(int k = 0; k < 1; ++k) {
                            dp[i][j][1][k] = min(dp[i][j][1][k], dp[i - 1][j][0][k] + price);
                        }
                    }
                    break;
                default:
                    for(int j = 0; j < 1; ++j) {
                        for(int k = 0; k < 1; ++k) {
                            dp[i][j][k][1] = min(dp[i][j][k][1], dp[i - 1][j][k][0] + price);
                        }
                    }
                    break;
            }
        }
    }

    cout << dp[n - 1][1][1][1] << '\n';
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        solve();
    }
}
