#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f;
const int SZ = (1 << 0) | (1 << 1) | (1 << 2);
const int MXN = SZ + 20;

void solve()
{
    int n, price{}, next{};
    cin >> n;
    string s;

    int dp[MXN];

    memset(dp, INF, sizeof dp);
    dp[0] = 0;

    for(int i = 0; i < n; ++i) {
        cin >> price >> s;
        for(char c: s) {
            for(int j = 0; j <= SZ; ++j) {
                next = j | (1 << (c - 'A'));
                dp[next] = min(dp[next], dp[j] + price);
            }
        }
    }

    cout << dp[SZ] << '\n';
}

int main()
{
    int a = (1 << 0) | (1 << 1) | (1 << 2);
    cout << a;
}
