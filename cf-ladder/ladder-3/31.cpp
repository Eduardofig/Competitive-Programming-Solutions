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

int n, m;
//int k;
//int a[MXN];
//int b[MXN];
string grid[MXN];
 
void solve()
{
    vector<int> ni(n, 0), nj(m, 0);

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(grid[i][j] == '*') {
                ni[i]++;
                nj[j]++;
            }
        }
    }

    int ans = INF;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            ans = min(ans, (n - ni[i]) + (m - nj[j]) - (grid[i][j] == '.'));
        }
    }

    cout << ans << '\n';
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
            cin >> grid[i];
        }

        solve();
    }
}
