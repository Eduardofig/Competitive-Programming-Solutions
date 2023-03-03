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

int n, m;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
vector<int> g[MXN];
bool vis[MXN]{};
int shift = 0;

void bfs(int st)
{
    queue<int> q;

    int sz = 0;
    q.push(st);

    while(!q.empty()) {

        int curr = q.front();
        q.pop();

        if(vis[curr]) {
            continue;
        }

        sz++;
        vis[curr] = true;

        for(int neigh: g[curr]) {
            if(!vis[neigh]) {
                q.push(neigh);
            }
        }
    }

    shift += sz - 1;
}

void solve()
{
    for(int u = 0; u < n; ++u) {
        if(!vis[u]) {
            bfs(u);
        }
    }

    cout << (1LL << shift) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        u--, v--;

        g[u].push_back(v);
        g[v].push_back(u);
    }
    solve();
}
