#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 200;
const int INF = 0x3f3f3f3f;
const int MOD = 1e7 + 9;

int n, m;
//int k;
//int a[MXN];
//int b[MXN];
int grid[MXN][MXN];
 
void solve()
{
    int tot[n];
    memset(tot, 0, sizeof tot);
    
    for(int city = 0; city < m; ++city) {
        auto wcand = max_element(&grid[city][0], &grid[city][n]) - &grid[city][0];

        tot[wcand]++;
    }


    cout << max_element(&tot[0], &tot[n]) - &tot[0] + 1 << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    solve();
}
