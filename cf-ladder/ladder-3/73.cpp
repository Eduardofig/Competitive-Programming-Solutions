#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e3 + 3;
const int INF = 0x3f3f3f3f;

const bool MULTIPLE_TESTCASES = 0;

int n, m;
//int a[MXN];
//int b[MXN];
//string s;
string grid[MXN];
int cnti[MXN]{};
int cntj[MXN]{};

void solve()
{
    int tot = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == '*') {
                tot++;
                cnti[i]++;
                cntj[j]++;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(cnti[i] + cntj[j] - (grid[i][j] == '*') == tot) {
                cout << "YES\n" << i + 1 << ' ' << j + 1 << '\n';
                return;
            }
        }
    }

    cout << "NO\n";

}

void read()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> grid[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    if(MULTIPLE_TESTCASES) {
        int t;
        cin >> t;
        while(t--) {
            read();
            solve();
        }
    } else {
        read();
        solve();
    }
}
