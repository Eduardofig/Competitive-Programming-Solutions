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
// vector<int> em(MXN);
vector<int> dep(MXN, -1);
vector<pair<int, int>> qu(MXN);
// vector<int> b(MXN);
// vector<int> v(MXN);
vector<vector<int>> g(MXN, vector<int>());
// string s;

vector<vector<int>> par(MXN, vector<int>(32));

int nxt()
{
    int x;
    cin >> x;
    return x;
}

void dfs(int u)
{
    // cout << "dfs:" << u << '\n';
    for(int v: g[u]) {
        if(dep[v] == -1) {
            dep[v] = dep[u] + 1;
            dfs(v);
        }
    }
}

void init()
{
    fill(All(par[0]), 0);
    dep[0] = 1;

    For(u, n) {
        Foro(pow, 32) {
            par[u][pow] = par[par[u][pow - 1]][pow - 1];
        }
    }

    dfs(0);
}

void solve()
{
    init();

    Fore(qu, u, v) {
        if(dep[u] > dep[v]) {
            swap(u, v);
        }

        int diff = dep[v] - dep[u];

        For(mask, 32) {
            if(diff & (1 << mask)) {
                v = par[v][mask];
            }
        }

        assert(dep[u] == dep[v]);

        Forr(mask, 32) {
            int nxtu = par[u][mask];
            int nxtv = par[v][mask];

            if(nxtv != nxtu) {
                u = nxtu;
                v = nxtv;
            }
        }

        if(u == v) {
            cout << u + 1 << '\n';
            continue;
        }

        cout << par[u][0] + 1 << '\n';
    }
}

void read()
{
    cin >> n;
    qu.resize(nxt());

    fill(All(par[0]), 0);
    Foro(u, n) {
        par[u][0] = nxt() - 1;
        g[par[u][0]].pb(u);
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
