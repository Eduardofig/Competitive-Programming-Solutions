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
const ll INF = LONG_LONG_MAX;

const bool MULTIPLE_TESTCASES = 0;

ull l, r, k;
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

ll binexp(ll k, ll p)
{
    int curr = 1;

    while(p > 0) {
        if(p % 2 == 1) {
            curr *= k;
        }

        k *= k;
        p /= 2;
    }

    return curr;

}

void solve()
{
    ull curr = 1;

    while(curr < l) {
        if(k > ULLONG_MAX / curr) {
            Prn(-1);
            return;
        }
        curr *= k;
    }


    bool printed = false;
    while(curr <= r) {
        Pr(curr);
        printed = true;

        if(k > ULLONG_MAX / curr) {
            break;
        }

        curr *= k;
    }

    if(!printed) {
        Pr(-1);
    }

    Prn("");
}

void read()
{
    cin >> l >> r >> k;
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
