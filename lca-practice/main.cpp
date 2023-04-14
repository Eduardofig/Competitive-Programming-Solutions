#include <bits/stdc++.h>

#define For(i, n) for(int i = 0; i < (int)(n); ++i)
#define Foro(i, n) for(int i = 1; i < (int)(n); ++i)
#define Forr(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define Forl(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define Fore(v, ...) for(auto &[__VA_ARGS__]: (v))
#define All(x) (x).begin(), (x).end()
#define Mini(x, y) (x) = min((x), (y))
#define Maxi(x, y) (x) = max((x), (y))
#define pb push_back
#define eb emplace_back
#define ii pair<int, int>
#define iii tuple<int, int, int>

using namespace std;

using ui = unsigned int;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;

const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;

const bool MULTIPLE_TESTCASES = 0;

ll n, m, k, p, u, x, w, z;
// vector<int> a(MXN);
// vector<int> b(MXN);
// vector<int> v(MXN);
vector<vector<int>> g(MXN, vector<int>());
// string s;

struct lca_blifting
{
    vector<int> depth;
    vector<vector<int>> par;

    int ROOT = 0;
    const int MXLOG = 32;

    void dfs(int u, int prev)
    {
        par[u][0] = prev;
        for(int pow = 1; pow < MXLOG; ++pow) {
            par[u][pow] = par[par[u][pow - 1]][pow - 1];
        }

        for(int v: g[u]) {
            // Unvisited
            if(depth[v] == -1) {
                depth[v] = depth[u] + 1;
                dfs(v, u);
            }
        }
    }

    lca_blifting(int n, int root = 0): depth(n, -1), par(n, vector<int>(32, -1)), ROOT{ root }
    {
        fill(par[ROOT].begin(), par[ROOT].end(), ROOT);
        depth[ROOT] = 0;

        dfs(ROOT, ROOT);
    }

    int get_lca(int u, int v)
    {
        if(depth[u] > depth[v]) {
            swap(u, v);
        }

        int diff = depth[v] - depth[u];

        for(int mask = 0; mask < MXLOG; ++mask) {
            if((diff & (1 << mask)) != 0) {
                v = par[v][mask];
            }
        }

        assert(depth[v] == depth[v]);

        for(int mask = MXLOG - 1; mask >= 0 && par[u][0] != par[v][0]; --mask) {
            int nextu = par[u][mask];
            int nextv = par[v][mask];

            if(nextu != nextv) {
                u = nextu;
                v = nextv;
            }
        }

        if(u == v) {
            return u;
        } else {
            return par[u][0];
        }
    }
};

int nxt()
{
    int x;
    cin >> x;
    return x;
}

vector<ii> qu;
vector<int> par;
vector<int> tot;
vector<int> ans;
vector<bool> vis;

void dfs(int u, int prev)
{
    vis[u] = true;
    par[u] = prev;
    ans[u] = tot[u];

    for(int v: g[u]) {
        if(!vis[v]) {
            dfs(v, u);
            ans[u] += ans[v];
        }
    }
}

void dfspar(int u, int prev)
{
    vis[u] = true;
    par[u] = prev;

    for(int v: g[u]) {
        if(!vis[v]) {
            dfs(v, u);
        }
    }
}

void solve()
{
    int root = 0;

    lca_blifting lcab(MXN, root);

    ans.resize(n, 0);
    tot.resize(n, 0);
    vis.resize(n, false);

    dfspar(root, root);
    fill(All(vis), false);

    Fore(qu, u, v) {
        tot[u]++;
        tot[v]++;

        int lca = lcab.get_lca(u, v);
        tot[lca]--;

        if(lca != root) {
            tot[par[lca]]--;
        }
    }

    dfs(root, root);

    For(u, n) {
        cout << ans[u] << ' ';
    }

    cout << '\n';
}

void read()
{
    cin >> n;
    par.resize(n);
    qu.resize(nxt());

    iota(All(par), 0);

    Foro(i, n) {
        int u = nxt() - 1;
        int v = nxt() - 1;
        g[u].pb(v);
        g[v].pb(u);
    }


    Fore(qu, u, v) {
        u = nxt() - 1;
        v = nxt() - 1;
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
