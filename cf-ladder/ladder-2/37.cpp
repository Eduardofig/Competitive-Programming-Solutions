#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e2 + 3;
const int INF = 0x3f3f3f3f;
const int MOD = 1e7 + 9;

int n;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
vector<pair<int, int>> v;
vector<int> g[MXN];
vector<bool> vis;

void dfs(int curr)
{
    vis[curr] = true;

    for(int neigh: g[curr]) {
        if(!vis[neigh]) {
            dfs(neigh);
        }
    }
}
 
void solve()
{
    for(int i = 0; i < n; ++i) {
        auto [x1, y1] = v[i];
        for(int j = 0; j < n; ++j) {
            if(j != i) {
                auto [x2, y2] = v[j];

                if(x2 == x1 || y2 == y1) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; ++i) {
        if(!vis[i]) {
            dfs(i);
            ans++;
        }
    }

    cout << ans - 1 << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n;
    v.resize(n);
    vis.resize(n, false);
    for(auto &[x, y]: v) {
        cin >> x >> y;
    }
    solve();
}
