#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 1e3;
const int INF = 0x3f3f3f3f;
const int MOD = 1e7 + 9;

int n, m;
//int k;
//int a[MXN];
//int b[MXN];
string grid[MXN];

void solve()
{
    int sti, stj;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(grid[i][j] == 'B') {
                sti = i;
                stj = j;
                goto next;
            }
        }
    }

next:

    int ei = sti, ej = stj;

    while(ei < n - 1 && grid[ei + 1][ej] == 'B') {
        ei++;
    }

    while(ej < m - 1 && grid[ei][ej + 1] == 'B') {
        ej++;
    }

    cout << (sti + ei + 2) / 2 << ' ' << (stj + ej + 2) / 2 << '\n';
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
