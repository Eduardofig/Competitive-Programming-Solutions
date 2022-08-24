#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 100;
const int INF = 0x3f3f3f3f;

int n, m;
int grid[MXN][MXN];

void solve()
{
    int mxi{}, mxj{};
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(grid[i][j] > grid[mxi][mxj]) {
                mxi = i;
                mxj = j;
            }
        }
    }

    int x = max(mxi + 1, n - mxi);
    int y = max(mxj + 1, m - mxj);

    cout << x * y << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> grid[i][j];
            }
        }
        solve();
    }
}
