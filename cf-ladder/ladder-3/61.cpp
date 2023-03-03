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

int n, q;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
vector<pair<int, int>> qs;
bool grid[2][MXN]{};

set<pair<int, int>> blocked;
 
void solve()
{
    for(auto &[x, y]: qs) {
        grid[x][y] ^= 1;

        if(y > 0) {
            if(grid[x ^ 1][y - 1] && grid[x][y] || grid[x][y - 1] && grid[x ^ 1][y]) {
                blocked.insert({y - 1, y});
            } else {
                auto it = blocked.find({y - 1, y});
                if(it != blocked.end()) {
                    blocked.erase(it);
                }
            }
        }

        if(y < n - 1) {
            if(grid[x ^ 1][y + 1] && grid[x][y] || grid[x][y + 1] && grid[x ^ 1][y]) {
                blocked.insert({y, y + 1});
            } else {
                auto it = blocked.find({y, y + 1});
                if(it != blocked.end()) {
                    blocked.erase(it);
                }
            }
        }

        if(grid[x][y] && grid[x ^ 1][y]) {
            blocked.insert({y, y});
        } else {
            auto it = blocked.find({y, y});
            if(it != blocked.end()) {
                blocked.erase(it);
            }
        }

        if(blocked.empty()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> q;
    qs.resize(q);

    for(auto &[x, y]: qs) {
        cin >> x >> y;
        x--, y--;
    }

    solve();
}
