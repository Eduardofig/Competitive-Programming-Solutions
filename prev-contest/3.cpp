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

#define int ll

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

vi c;
vi has;

vvi ids;
vvi need(MXN, vi(10, 0));
vb vis(MXN, false);

ll nxt()
{
    ll x;
    cin >> x;
    return x;
}

void dfs(int u)
{
    vis[u] = true;

    for(int v: g[u]) {
        if(!vis[v]) {
            dfs(v);
        }

        For(r, 10) {
            need[u][r] = min((int)1e8 + 30, need[u][r] + need[v][r]);
        }
    }
}

void solve()
{
    For(u, n) {
        dfs(u);
    }

    int ans = 0;
    For(sub, (1 << n)) {
        vi needcurr(10, 0);
        int tot = 0;
        For(mask, n) {
            if((1 << mask) & sub) {
                tot++;
                For(r, 10) {
                    needcurr[r] += need[mask][r];
                }
            }
        }

        bool ok = true;
        For(r, 10) {
            ok = ok && (needcurr[r] <= has[r]);
        }

        if(ok) {
            Maxi(ans, tot);
        }
    }

    Prn(ans);
}

void read()
{
    cin >> n >> m;
    c.Rz(m);
    has.Rzz(10, 0);

    int curr = 0;
    For(u, m) {
        cin >> c[u];

        if(c[u] == 0) {
            cin >> has[curr];
            need[u][curr++] = 1;
        } else {
            For(j, c[u]) {
                int v = nxt() - 1;
                g[u].Pb(v);
            }
        }
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
