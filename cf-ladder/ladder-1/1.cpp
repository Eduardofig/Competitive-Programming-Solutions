#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 53;
const int INF = 0x3f3f3f3f;
const int MOD = 1e7 + 9;

int n, m;
//int k;
//int a[MXN];
//int b[MXN];
string grid[MXN];
 
void solve()
{
    int min_i = INF, min_j = INF, max_i = 0, max_j = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(grid[i][j] == '*') {
                min_i = min(min_i, i);
                max_i = max(max_i, i);
                min_j = min(min_j, j);
                max_j = max(max_j, j);
            }
        }
    }

    for(int i = min_i; i <= max_i; ++i) {
        for(int j = min_j; j <= max_j; ++j) {
            cout << grid[i][j];
        }
        cout << '\n';
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    solve();
}
