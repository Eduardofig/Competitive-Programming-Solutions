#include <bits/stdc++.h>

#define For(i, n) for(int (i) = 0; (i) < (int)(n); ++(i))
#define Foro(i, n) for(int (i) = 1; (i) < (int)(n); ++(i))
#define Forr(i, n) for(int (i) = (int)(n) - 1; (i) >= 0; --(i))
#define Forl(i, n) for(ll (i) = 0; (i) < (ll)(n); ++(i))
#define Fore(v, ...) for(auto &[__VA_ARGS__]: (v))
#define All(x) (x).begin(), (x).end()
#define Mini(x, y) (x) = min((x), (y))
#define Maxi(x, y) (x) = max((x), (y))
#define Pb push_back
#define Eb emplace_back
#define Lb(x, y) lower_bound(x, (y))
#define Ub(x, y) upper_bound(x, (y))
#define Rz(x) resize((x))
#define Rzz(x, y) resize((x), (y))
#define Read(x) generate(All((x)), nxt)
#define Pr(x) cout << (x) << ' '
#define Prn(x) cout << (x) << '\n'
#define Has(x, y) ((x).find(y) != (x).end())

// #define int ll

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;
using pll = pair<ll, ll>;
using tll = tuple<ll, ll, ll>;
using iii = tuple<int, int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vpll = vector<pll>;
using vvpll = vector<vpll>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;
using vvvi = vector<vvi>;
using vvvii = vector<vvii>;
using vb = vector<bool>;
using vvb = vector<vb>;

const int MXN = 5e5 + 100;
const int INF = INT_MAX;

const bool MULTIPLE_TESTCASES = 0;

int n, m;
// vi a(MXN);
// vi b(MXN);
// vi v(MXN);
vvi g(MXN, vi());
// string s;

ll nxt()
{
    ll x;
    cin >> x;
    return x;
}

struct unionfind
{
    vi par, sz;

    unionfind(int n): par(n), sz(n, 1)
    {
        iota(All(par), 0);
    }

    int find(int u)
    {
        if(par[u] == u) {
            return u;
        }

        return par[u] = find(par[u]);
    }

    void unite(int u, int v)
    {
        int small = find(u), big = find(v);

        if(small == big) {
            return;
        }

        if(sz[small] > sz[big]) {
            swap(small, big);
        }

        par[small] = big;

        sz[big] += sz[small];
    }
};

void solve()
{
    unionfind uf(MXN);

    vi sz(n, 0);
    vi mn(n, INF);

    For(u, n) {
        for(int v: g[u]) {
            uf.unite(u, v);
        }
    }

    For(u, n) {
        sz[uf.find(u)]++;
        Mini(mn[uf.find(u)], (int)g[u].size());
    }

    bool ok = true;
    For(u, n) {
        ok = ok && mn[uf.find(u)] == sz[uf.find(u)] - 1;
    }

    if(ok) {
        Prn("YES");
    } else {
        Prn("NO");
    }
}

void read()
{
    cin >> n >> m;

    For(i, m) {
        int u = nxt() - 1, v = nxt() - 1;

        g[u].Pb(v);
        g[v].Pb(u);
    }
}

int32_t main()
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
