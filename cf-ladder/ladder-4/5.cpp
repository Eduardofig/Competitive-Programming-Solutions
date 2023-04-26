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
// vvi g(MXN, vi());
// string s;

ll nxt()
{
    ll x;
    cin >> x;
    return x;
}

vb vis(MXN, false);

const int MXSPF = 1e5;

int spf[MXSPF];

void sievespf()
{
    spf[1] = 1;

    for(int i = 2; i < MXSPF; ++i) {
        spf[i] = i;
    }

    for(int i = 4; i < MXSPF; i += 2) {
        spf[i] = 2;
    }

    for(int i = 3; i * i < MXSPF; ++i) {
        if(spf[i] == i) {
            for(int j = i * i; j < MXSPF; j += i) {
                if(spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

vector<int> factor(int x)
{
    vector<int> factors;
    while(x != 1) {
        factors.push_back(spf[x]);
        x = x / spf[x];
    }
    return factors;
}

void solve()
{
    if(n == 1) {
        Prn(0);
        return;
    }

    sievespf();

    set<int> ans;

    for(int i = 2; i <= n; ++i) {
        for(int fact: factor(i)) {
            int og = fact;
            while(fact <= n && !Has(ans, fact)) {
                ans.insert(fact);
                fact *= og;
            }
        }
    }

    Prn(ans.size());
    for(int i: ans) {
        Pr(i);
    }
    Prn("");
}

void read()
{
    cin >> n;
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
