#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 103;
const int INF = 0x3f3f3f3f;
const int MOD = 1e7 + 9;

int n, m;
char grid[MXN][MXN];
//int k;
//int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    set<char> s({'B', 'W', 'G'});
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(s.find(grid[i][j]) == s.end()) {
                cout << "#Color\n";
                return;
            }
        }
    }
    cout << "#Black&White\n";
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
