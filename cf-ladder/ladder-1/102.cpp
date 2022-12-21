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

int n;
//int k;
//int a[MXN];
//int b[MXN];
string grid[8];
 
void solve()
{
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            if(grid[i][j] == grid[i][j + 1 % 8]) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    for(int i = 0; i < 8; ++i) {
        cin >> grid[i];
    }

    solve();
}
