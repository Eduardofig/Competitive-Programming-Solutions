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
//string s;
int grid[50][50];
 
void solve()
{
    bool ok[50][50]{};
    vector<pair<int, int>> ans;

    for(int i = 0; i + 1 < n; ++i) {
        for(int j = 0; j + 1 < m; ++j) {
            int cnt = 0;
            for(int k = 0; k < 2; ++k) {
                for(int l = 0; l < 2; ++l) {
                    cnt += grid[i + k][j + l];
                }
            }

            if(cnt == 4) {
                ans.emplace_back(i + 1, j + 1);
                for(int k = 0; k < 2; ++k) {
                    for(int l = 0; l < 2; ++l) {
                        ok[i + k][j + l] = true;
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(grid[i][j] && !ok[i][j]) {
                cout << "-1\n";
                return;
            }
        }
    }

    cout << ans.size() << '\n';

    for(auto &[i, j]: ans) {
        cout << i << ' ' << j << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    solve();
}
