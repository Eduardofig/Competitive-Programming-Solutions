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
const int loss = 0;
const int draw = 1;
const int win = 2;

bool is_inbounds(int l, int r)
{
    return l >= 0 && l < r && r < n;
}

void solve()
{
    int n = s.size();

    int dp[n][n];

    memset(dp, draw, sizeof dp);

    for(int i = 0; i < n - 1; ++i) {
        dp[i][i + 1] = (s[i] == s[i + 1]? draw: win);
    }

    //maximize even, minimize odd
    for(int len = 1; len < n; len += 2) {
        for(int l = 0; l + len < n; ++l) {
            int r = l + len;

            int turn = (len + 3) % 2;

            if(dp[l][r] != -1) {
                if(l > 0 && r < n - 1) {

                    if(turn == 0) {
                        if(s[l - 1] != s[r + 1]) {
                            dp[l - 1][r + 1] = win;
                        } else {
                            dp[l - 1][r + 1] = max(dp[l - 1][r + 1], dp[l][r]);
                        }
                    } else {
                        if(s[l - 1] != s[r + 1]) {
                            dp[l - 1][r + 1] = loss;
                        } else {
                            dp[l - 1][r + 1] = min(dp[l - 1][r + 1], dp[l][r]);
                        }

                    }
                }

                if(l >= 2) {

                    if(turn == 0) {
                        if(s[l - 1] == s[l - 2]) {
                            dp[l - 2][r] = max(dp[l - 2][r], dp[l][r]);
                        } else {
                            int next = (s[l - 1] > s[l - 2]? win: loss);

                            dp[l - 2][r] = max(dp[l - 2][r], next);
                        }
                    } else {
                        if(s[l - 1] == s[l - 2]) {
                            dp[l - 2][r] = min(dp[l - 2][r], dp[l][r]);
                        } else {
                            int next = (s[l - 1] > s[l - 2]? win: loss);

                            dp[l - 2][r] = min(dp[l - 2][r], next);
                        }
                    }
                }

                if(r <= n - 3) {
                    if(turn == 0) {
                        if(s[r + 1] == s[r + 2]) {
                            dp[l][r + 2] = max(dp[l][r + 2], dp[l][r]);
                        } else {
                            int next = (s[r + 1] > s[r + 2]? win: loss);

                            dp[l][r + 2] = max(dp[l][r + 2], next);
                        }
                    } else {
                        if(s[r + 1] == s[r + 2]) {
                            dp[l][r + 2] = min(dp[l][r + 2], dp[l][r]);
                        } else {
                            int next = (s[r + 1] > s[r + 2]? win: loss);

                            dp[l][r + 2] = min(dp[l][r + 2], next);
                        }
                    }

                }
            }
        }
    }

    cout << dp[0][n - 1] << '\n';

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        cin >> s;
        solve();
    }
}
