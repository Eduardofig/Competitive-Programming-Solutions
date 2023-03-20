#include <bits/stdc++.h>
#include <cstring>
 
using namespace std;
 
using ui = unsigned int;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e3 + 3;
const int INF = 0x3f3f3f3f;

const bool MULTIPLE_TESTCASES = 0;

int h, w;
int c[MXN];
int r[MXN];
//int b[MXN];
//string s;
int grid[MXN][MXN];

const int MOD = 1e9 + 7;
    
int mod_add(int a, int b)
{
    a %= MOD;
    b %= MOD;

    return (a + b) % MOD;
}
    
int mod_mul(int a, int b)
{
    a %= MOD;
    b %= MOD;
    
    return (a * b) % MOD;
}

int mod_sub(int a, int b)
{
    a %= MOD;
    b %= MOD;
    
    return (((a - b) % MOD) + MOD) % MOD;
}

void solve()
{
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < r[i]; j++) {
            grid[i][j] = 1;
        }
        if(r[i] < w) {
            grid[i][r[i]] = 0;
        }
    }

    for(int j = 0; j < w; j++) {
        for(int i = 0; i < c[j]; i++) {
            if(grid[i][j] == 0) {
                cout << 0 << '\n';
                return;
            }

            grid[i][j] = 1;
        }

        if(c[j] < h) {
            if(grid[c[j]][j] == 1) {
                cout << 0 << '\n';
                return;
            }

            grid[c[j]][j] = 0;
        }
    }

    int cnt = 0;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cnt += grid[i][j] == -1;
        }
    }

    int ans = 1;
    for(int i = 0; i < cnt; i++) {
        ans = mod_mul(ans, 2);
    }

    cout << ans << '\n';
}

void read()
{
    cin >> h >> w;
    for(int i = 0; i < h; i++) {
        cin >> r[i];
    }

    for(int i = 0; i < w; i++) {
        cin >> c[i];
    }
    
    memset(grid, -1, sizeof grid);
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
