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
string grid[4];
 
void solve()
{
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            int cnt = 0;

            for(int k = 0; k < 2; ++k) {
                for(int l = 0; l < 2; ++l) {
                    if(grid[i + k][j + l] == '#') {
                        cnt++;
                    }
                }
            }

            if(cnt >= 3 || cnt <= 1) {
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for(int i = 0; i < 4; ++i) {
        cin >> grid[i];
    }
    solve();
}
