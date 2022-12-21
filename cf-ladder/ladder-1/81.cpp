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
string grid[503];
 
bool inbound(int i, int j) {
    return i >= 0 && i < n && j < m && j >= 0;
}

void solve()
{
    int di[] = {1, 0, -1, 0};
    int dj[] = {0, 1, 0, -1};

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(grid[i][j] == 'W') {
                for(int k = 0; k < 4; ++k) {
                    int nexti = i + di[k], nextj = j + dj[k];
                    if(inbound(nexti, nextj)) {
                        if(grid[nexti][nextj] == 'S') {
                            cout << "No\n";
                            return;
                        } else if(grid[nexti][nextj] == '.') {
                            grid[nexti][nextj] = 'D';
                        }
                    }
                }
            }
        }
    }
    cout << "Yes\n";
    for(int i = 0; i < n; ++i) {
        cout << grid[i] << '\n';
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
