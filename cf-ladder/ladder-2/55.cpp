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
//string s;
 
int nleaf[MXN]{};
vector<int> g[MXN];
bool vis[MXN]{};


int dfs(int curr)
{
    vis[curr] = true;

    if(g[curr].empty()) {
        return 1;
    }

    for(int neigh: g[curr]) {
        if(!vis[neigh]) {
            nleaf[curr] += dfs(neigh);
        }
    }

    return 0;
}

void solve()
{
    dfs(0);

    for(int v = 0; v < n; ++v) {
        if(!g[v].empty() && nleaf[v] < 3) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n;
    for(int v = 1; v < n; ++v) {
        int u;
        cin >> u;
        u--;

        g[u].push_back(v);
    }
    solve();
}
