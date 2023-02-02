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
vector<int> g[MXN];
ll ans = 0;

bool col[MXN]{};
int ncol[2]{};
bool vis[MXN]{};
bool vis2[MXN]{};

void dfs(int u)
{
    vis[u] = true;
    ncol[col[u]]++;
    for(int v: g[u]) {
        if(!vis[v]) {
            col[v] = !col[u];
            dfs(v);
        }
    }
}

void dfs2(int u)
{
    vis2[u] = true;
    if(col[u]) {
        ans += max(ncol[!col[u]] - (int)g[u].size(), 0);
    }

    for(int v: g[u]) {
        if(!vis2[v]) {
            dfs2(v);
        }
    }
}

void solve()
{
    dfs(0);
    dfs2(0);

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;

        g[u].push_back(v);
        g[v].push_back(u);
    }
    solve();
}
