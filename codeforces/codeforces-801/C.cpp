#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MXN = 1e3 + 3, INF = 0x3f3f3f3f;

int dp_mx[MXN][MXN], dp_min[MXN][MXN];
int grid[MXN][MXN];
int n, m;

void solve()
{
    memset(dp_mx, -INF, sizeof dp_mx);
    memset(dp_min, INF, sizeof dp_min);

    dp_mx[0][0] = dp_min[0][0] = grid[0][0];

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            dp_mx[i + 1][j] = max(dp_mx[i][j] + grid[i + 1][j], dp_mx[i + 1][j]);
            dp_mx[i][j + 1] = max(dp_mx[i][j + 1], dp_mx[i][j] + grid[i][j + 1]);
            dp_min[i + 1][j] = min(dp_min[i][j] + grid[i + 1][j], dp_min[i + 1][j]);
            dp_min[i][j + 1] = min(dp_min[i][j] + grid[i][j + 1], dp_min[i][j + 1]);
        }
    }


    if(dp_mx[n - 1][m - 1] < 0 || dp_min[n - 1][m - 1] > 0) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    ll t;
    cin >> t;
    for(int test = 0; test < t; ++test) {
        cin >> n >> m;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> grid[i][j];
            }
        }

        solve();
    }
}
