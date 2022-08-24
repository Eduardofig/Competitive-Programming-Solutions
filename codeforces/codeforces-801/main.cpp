#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 1e4 + 3;
const int INF = 0x3f3f3f3f;
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> grid[i][j];
            }
        }

        vector<vector<int>> mx(n, vector<int>(m, INF));
        vector<vector<int>> mn(n, vector<int>(m, INF));

        mx[0][0] = 0;
        mn[0][0] = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                mx[i + 1][j] = max(mx[i][j] + grid[i][j], mx[i + 1][j]);
                mx[i][j + 1] = max(mx[i][j] + grid[i][j], mx[i][j + 1]);
                mn[i + 1][j] = min(mn[i][j] + grid[i][j], mn[i + 1][j]);
                mn[i][j + 1] = min(mn[i][j] + grid[i][j], mn[i][j + 1]);
            }
        }

        if(mx[n][m] > 0 && mn[n][m] < 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
