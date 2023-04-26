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

vi color(MXN, -1);
bool ok = true;

void dfs(int u)
{
    for(int v: g[u]) {
        ok = ok && color[v] != color[u];

        if(color[v] == -1) {
            color[v] = color[u] ^ 1;
            dfs(v);
        }
    }
}

ll nxt()
{
    ll x;
    cin >> x;
    return x;
}

void solve()
{
    For(u, n) {
        if(color[u] == -1 && !g[u].empty()) {
            color[u] = 0;
            dfs(u);
        }
    }

    if(!ok) {
        Prn(-1);
        return;
    }

    set<int> one, zero;

    For(u, n) {
        if(color[u] == 1) {
            one.insert(u);
        } else if(color[u] == 0) {
            zero.insert(u);
        }
    }

    Prn(one.size());

    for(int u: one) {
        Pr(u + 1);
    }

    Prn("");

    Prn(zero.size()); 

    for(int u: zero) {
        Pr(u + 1);
    }
    Prn("");
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
