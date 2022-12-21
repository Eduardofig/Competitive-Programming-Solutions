#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 3e5 + 3;
const int INF = 0x3f3f3f3f;
const int MOD = 998224353;

int n, m;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
 
string grid[MXN];

ull mod_mul(ull a, ull b)
{
    a %= MOD;
    b %= MOD;

    return (a * b) % MOD;
}

ull mod_pow(ull x, ull y)
{
 
    // Initialize answer
    ull res = 1;
 
    // Check till the number becomes zero
    while (y > 0) {
 
        // If y is odd, multiply x with result
        if (y % 2 == 1)
            res = mod_mul(res, x);
 
        // y = y/2
        y = y >> 1;
 
        // Change x to x^2
        x = mod_mul(x, x);
    }
    return res % MOD;
}

ull mod_add(ull a, ull b)
{
    a %= MOD;
    b %= MOD;

    return (a + b) % MOD;
}

ull mod_sub(ull a, ull b)
{
    a %= MOD;
    b %= MOD;

    return ((a - b) + MOD) % MOD;
}


void solve()
{
    ull w = 0;
    ull ans = 0;
    for(ull i = 0; i < n; ++i) {
        for(ull j = 0; j < m; ++j) {
            if(grid[i][j] == 'o') {
                w++;
            }
        }
    }

    ull p2 = mod_pow(2, w - 2);
    ull p3 = mod_pow(2, w - 3);
    ull p4 = mod_pow(2, w - 4);

    for(ull i = 0; i < n; ++i) {
        for(ull j = 0; j < m; ++j) {
            if(i < n - 1 && grid[i][j] == grid[i + 1][j] && grid[i][j] == 'o') {
                ans = mod_add(ans, p2);
                if(i > 0 && grid[i - 1][j] == 'o') {
                    ans = mod_sub(ans, p3);
                }

                if(i > 1 && grid[i - 2][j] == 'o') {
                    ans = mod_add(ans, p4);
                }
            }

            if(j < m - 1 && grid[i][j] == grid[i][j + 1] && grid[i][j] == 'o') {
                ans = mod_add(ans, p2);
                if(j > 0 && grid[i][j - 1] == 'o') {
                    ans = mod_sub(ans, p3);
                }

                if(j > 1 && grid[i][j - 2] == 'o') {
                    ans = mod_add(ans, p4);
                }
            }
        }
    }

    cout << ans % MOD << '\n';
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
