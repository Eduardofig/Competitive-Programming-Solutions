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
#define Rz(x, y) resize((x), (y))
#define Read(x) generate(All((x)), nxt)
#define Pr(x) cout << (x) << ' '
#define Prn(x) cout << (x) << '\n'

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
 
const int MXN = 5e5 + 100;
const int INF = 0x3f3f3f3f;

const bool MULTIPLE_TESTCASES = 0;

int n, m;
// vi a(MXN);
// vi b(MXN);
// vi v(MXN);
vvi g(MXN, vi());
// string s;

vvi cost(15, vi(10, 0));
vi has(10);

vector<bool> isleaf(MXN, false);
vector<bool> vis(MXN, false);

void dfs(int u)
{
	if(isleaf[u]) {
		cost[u][u] = 1;
		return;
	}

	for(int v: g[u]) {
		if(!vis[v]) {
			dfs(v);
		}

		for(int i = 0; i < 10; ++i) {
			cost[u][i] += cost[v][i];
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
    int ans = 0;
	for(int subs = 0; subs < (1 << n); ++subs) {
		vi curr_cost(10, 0);
		for(int mask = 0; mask < n; ++mask) {
			if(mask & subs) {
				for(int i = 0; i < 10; ++i) {
					curr_cost[i] += cost[mask][i];
				}
			}
		}

		bool ok = true;
		for(int i = 0; i < 10; ++i) {
			ok = ok and curr_cost[i] <= has[i];
		}

		if(ok) {
			Maxi(ans, __builtin_popcount(subs));
		}
	}

	cout << ans << '\n';
}

void read()
{
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
